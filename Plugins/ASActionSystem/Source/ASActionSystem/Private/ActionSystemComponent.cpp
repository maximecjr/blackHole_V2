// Copyright Epic Games, Inc. All Rights Reserved.

#include "ActionSystemComponent.h"
#include "Ability.h"

UActionSystemComponent::UActionSystemComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

bool UActionSystemComponent::AddAbility(UAbility* Ability, AActor* Instigator)
{
    if (Ability && Ability->CanAddAbility(Instigator))
    {
        Abilities.Add(Ability);
        Ability->OnAbilityAdded(Instigator);
        return true;
    }
    return false;
}

bool UActionSystemComponent::RemoveAbility(FGameplayTag AbilityTag, AActor* Instigator)
{
    for (int32 i = 0; i < Abilities.Num(); ++i)
    {
        if (Abilities[i]->AbilityTag == AbilityTag)
        {
            Abilities[i]->OnAbilityRemoved(Instigator);
            Abilities.RemoveAt(i);
            return true;
        }
    }
    return false;
}

void UActionSystemComponent::TriggerAbility(FGameplayTag AbilityTag, AActor* Instigator, UWorld* World)
{
    for (UAbility* Ability : Abilities)
    {
        if (Ability->AbilityTag == AbilityTag && Ability->CanStartAbility(Instigator))
        {
            Ability->Start(Instigator,World);
        }
    }
}
