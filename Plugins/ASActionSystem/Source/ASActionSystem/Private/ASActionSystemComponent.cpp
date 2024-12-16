// Copyright Epic Games, Inc. All Rights Reserved.

#include "ASActionSystemComponent.h"
#include "Ability.h"

UASActionSystemComponent::UASActionSystemComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
}

void UASActionSystemComponent::BeginPlay()
{
    Super::BeginPlay();

    if (DefaultAttributes)
    {
        for (const FASAttributeData& AttributeData : DefaultAttributes->Attributes)
        {
            FASAttribute NewAttribute;
            NewAttribute.AttributeTag = AttributeData.AttributeTag;
            NewAttribute.CurrentValue = AttributeData.DefaultValue;
            NewAttribute.MinValue = AttributeData.MinValue;
            NewAttribute.MaxValue = AttributeData.MaxValue;

            AddAttribute(NewAttribute);
        }
    }
}
bool UASActionSystemComponent::SetAttributeValue(FGameplayTag AttributeTag, float Value)
{
    for (FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            Attr.CurrentValue = FMath::Clamp(Value, Attr.MinValue, Attr.MaxValue);
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::GetAttributeValue(FGameplayTag AttributeTag, float& OutValue) const
{
    for (const FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            OutValue = Attr.CurrentValue;
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::SetAttributeMaxValue(FGameplayTag AttributeTag, float Value)
{
    for (FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            Attr.MaxValue = Value;
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::GetAttributeMaxValue(FGameplayTag AttributeTag, float& OutValue) const
{
    for (const FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            OutValue = Attr.MaxValue;
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::SetAttributeMinValue(FGameplayTag AttributeTag, float Value)
{
    for (FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            Attr.MinValue = Value;
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::GetAttributeMinValue(FGameplayTag AttributeTag, float& OutValue) const
{
    for (const FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            OutValue = Attr.MinValue;
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::HasAttribute(FGameplayTag AttributeTag) const
{
    for (const FASAttribute& Attr : Attributes)
    {
        if (Attr.AttributeTag == AttributeTag)
        {
            return true;
        }
    }
    return false;
}

bool UASActionSystemComponent::AddAttribute(const FASAttribute& NewAttribute)
{
    if (!HasAttribute(NewAttribute.AttributeTag))
    {
        Attributes.Add(NewAttribute);
        return true;
    }
    return false;
}

bool UASActionSystemComponent::RemoveAttribute(FGameplayTag AttributeTag)
{
    for (int32 i = 0; i < Attributes.Num(); ++i)
    {
        if (Attributes[i].AttributeTag == AttributeTag)
        {
            Attributes.RemoveAt(i);
            return true;
        }
    }
    return false;
}

int32 UASActionSystemComponent::AddAttributeChangedDelegate(FGameplayTag AttributeTag, const FASAttributeChangeDelegate& Delegate)
{
    FASAttributeChangedHolder Holder;
    Holder.DelegateID = NextDelegateID++;
    Holder.Delegate = Delegate;

    AttributeChangedDelegates.Add(Holder);
    return Holder.DelegateID;
}

void UASActionSystemComponent::RemoveAttributeChangedDelegate(int32 DelegateID)
{
    AttributeChangedDelegates.RemoveAll([DelegateID](const FASAttributeChangedHolder& Holder)
    {
        return Holder.DelegateID == DelegateID;
    });
}

// Ajouter un délégué pour les ajouts d'attributs
int32 UASActionSystemComponent::AddAttributeAddedDelegate(const FASAttributeAddedDelegate& Delegate)
{
    FASAttributeAddedHolder Holder;
    Holder.DelegateID = NextDelegateID++;
    Holder.Delegate = Delegate;

    AttributeAddedDelegates.Add(Holder);
    return Holder.DelegateID;
}

void UASActionSystemComponent::RemoveAttributeAddedDelegate(int32 DelegateID)
{
    AttributeAddedDelegates.RemoveAll([DelegateID](const FASAttributeAddedHolder& Holder)
    {
        return Holder.DelegateID == DelegateID;
    });
}

// Ajouter un délégué pour les suppressions d'attributs
int32 UASActionSystemComponent::AddAttributeRemovedDelegate(const FASAttributeRemovedDelegate& Delegate)
{
    FASAttributeRemovedHolder Holder;
    Holder.DelegateID = NextDelegateID++;
    Holder.Delegate = Delegate;

    AttributeRemovedDelegates.Add(Holder);
    return Holder.DelegateID;
}

void UASActionSystemComponent::RemoveAttributeRemovedDelegate(int32 DelegateID)
{
    AttributeRemovedDelegates.RemoveAll([DelegateID](const FASAttributeRemovedHolder& Holder)
    {
        return Holder.DelegateID == DelegateID;
    });
}

void UASActionSystemComponent::HandleAbilityTriggered(AActor* Instigator)
{
    // Diffuse l'événement via le délégué local
    OnAbilityStarted.Broadcast(Instigator);
}

bool UASActionSystemComponent::AddAbility(UAbility* Ability, AActor* Instigator)
{
    bool bCanAdd = false;
    if (Ability)
    {
        Ability->CanAddAbility(Instigator, bCanAdd);
        if (bCanAdd)
        {
            Abilities.Add(Ability);
            Ability->OnAbilityAdded(Instigator);

            // Lier le délégué de l'Ability
            Ability->OnAbilityTriggered.AddDynamic(this, &UASActionSystemComponent::HandleAbilityTriggered);

            return true;        }
    }

    return false;
}

bool UASActionSystemComponent::RemoveAbility(FGameplayTag AbilityTag, AActor* Instigator)
{
    for (int32 i = 0; i < Abilities.Num(); ++i)
    {
        if (Abilities[i]->AbilityTag == AbilityTag)
        {
            UAbility* AbilityToRemove = Abilities[i];

            // Appeler OnAbilityRemoved pour effectuer des nettoyages éventuels
            AbilityToRemove->OnAbilityRemoved(Instigator);

            // Déconnecter les délégués
            AbilityToRemove->OnAbilityTriggered.RemoveAll(this);

            // Retirer l'ability
            Abilities.RemoveAt(i);
            return true;
        }
    }
    return false; // Ability non trouvée
}


void UASActionSystemComponent::TriggerAbility(FGameplayTag AbilityTag, AActor* Instigator, UWorld* World)
{
    for (UAbility* Ability : Abilities)
    {
        bool bCanStart = false;
        if (Ability->AbilityTag == AbilityTag)
        {
            Ability->CanStartAbility(Instigator, bCanStart);
            if (bCanStart)
            {
                Ability->Start(Instigator,World);

                // Appeler le délégué lié
                Ability->OnAbilityTriggered.Broadcast(Instigator);
            }
        }

    }
}
//GERE LES EFFECTS
bool UASActionSystemComponent::AddEffect(FGameplayTag EffectTag, AActor* Instigator, AActor* Receptor)
{
    //verifie s'il peut l'ajouter
    if (true)
    {
        EffectTags.AddTag(EffectTag);
        
        return true;
    }
    return false;//immunisé ou pas trouvé
}

bool UASActionSystemComponent::RemoveEffect(FGameplayTag EffectTag, AActor* Instigator, AActor* Receptor)
{
    //verifie s'il existe
    if (true)
    {
        EffectTags.RemoveTag(EffectTag);
        
        return true;
    }
    return false;//pas trouve
}

bool UASActionSystemComponent::OnEffectAdded(FGameplayTag EffectTag, AActor* Instigator, AActor* Receptor)
{
    return true;
}
bool UASActionSystemComponent::OnEffectRemoved(FGameplayTag EffectTag, AActor* Instigator, AActor* Receptor)
{
    return true;
}
void UASActionSystemComponent::OnEffectTriggered(FGameplayTag EffectTag, AActor* Instigator, AActor* Receptor){}


