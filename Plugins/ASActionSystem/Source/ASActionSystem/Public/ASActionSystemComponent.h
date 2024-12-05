// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Components/ActorComponent.h"
#include "ASAttribute.h"
#include "GameplayTagContainer.h"
#include "UASAttributeSet.h"
#include "UGameplayEffect.h"
#include "ASActionSystemComponent.generated.h"


DECLARE_DYNAMIC_DELEGATE_FourParams(FASAttributeChangeDelegate, FGameplayTag, AttributeTag, float, OldValue, float, NewValue, float, MaxValue);
DECLARE_DYNAMIC_DELEGATE_FourParams(FASAttributeAddedDelegate, FGameplayTag, AttributeTag, float, InitialValue, float, MinValue, float, MaxValue);
DECLARE_DYNAMIC_DELEGATE_OneParam(FASAttributeRemovedDelegate, FGameplayTag, AttributeTag);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityEvent, AActor*, Instigator);

class UAbility;


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASACTIONSYSTEM_API UASActionSystemComponent : public UActorComponent
{
    GENERATED_BODY()

private:
    UPROPERTY()
    TArray<FASAttribute> Attributes;

    // Liste des abilities attachées
    UPROPERTY()
    TArray<UAbility*> Abilities;

public:
    UASActionSystemComponent();
    void BeginPlay();

    UFUNCTION(BlueprintCallable, Category = "Attributes")
    bool SetAttributeValue(FGameplayTag AttributeTag, float Value);

    UFUNCTION(BlueprintCallable, Category = "Attributes")
    bool GetAttributeValue(FGameplayTag AttributeTag, float& OutValue) const;

    UFUNCTION(BlueprintCallable, Category = "Attributes")
    bool SetAttributeMaxValue(FGameplayTag AttributeTag, float Value);

    UFUNCTION(BlueprintCallable, Category = "Attributes")
    bool GetAttributeMaxValue(FGameplayTag AttributeTag, float& OutValue) const;

    UFUNCTION(BlueprintCallable, Category = "Attributes")
    bool SetAttributeMinValue(FGameplayTag AttributeTag, float Value);

    UFUNCTION(BlueprintCallable, Category = "Attributes")
    bool GetAttributeMinValue(FGameplayTag AttributeTag, float& OutValue) const;

    UFUNCTION(BlueprintCallable, Category = "Attributes")
    bool HasAttribute(FGameplayTag AttributeTag) const;

    UFUNCTION(BlueprintCallable, Category = "Attributes")
    bool AddAttribute(const FASAttribute& NewAttribute);

    UFUNCTION(BlueprintCallable, Category = "Attributes")
    bool RemoveAttribute(FGameplayTag AttributeTag);

    // Gestion des délégués pour les changements d'attributs
    UFUNCTION(BlueprintCallable, Category = "Attributes")
    int32 AddAttributeChangedDelegate(FGameplayTag AttributeTag, const FASAttributeChangeDelegate& Delegate);
    UFUNCTION(BlueprintCallable, Category = "Attributes")
    void RemoveAttributeChangedDelegate(int32 DelegateID);

    // Gestion des délégués pour les ajouts d'attributs
    UFUNCTION(BlueprintCallable, Category = "Attributes")
    int32 AddAttributeAddedDelegate(const FASAttributeAddedDelegate& Delegate);
    UFUNCTION(BlueprintCallable, Category = "Attributes")
    void RemoveAttributeAddedDelegate(int32 DelegateID);

    // Gestion des délégués pour les suppressions d'attributs
    UFUNCTION(BlueprintCallable, Category = "Attributes")
    int32 AddAttributeRemovedDelegate(const FASAttributeRemovedDelegate& Delegate);
    UFUNCTION(BlueprintCallable, Category = "Attributes")
    void RemoveAttributeRemovedDelegate(int32 DelegateID);

    UFUNCTION()
    void HandleAbilityTriggered(AActor* Instigator);

    // Ajout et suppression d'abilities
    UPROPERTY(BlueprintAssignable)
    FOnAbilityEvent OnAbilityStarted;

    // Ajoute une ability et connecte ses délégués
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    bool AddAbility(UAbility* Ability, AActor* Instigator);

    UFUNCTION(BlueprintCallable, Category = "Abilities")
    bool RemoveAbility(FGameplayTag AbilityTag, AActor* Instigator);

    // Déclenche une ability spécifique
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    void TriggerAbility(FGameplayTag AbilityTag, AActor* Instigator);

    //GESTION DES EFFECTS 
    //contient les tags des effets
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
    FGameplayTagContainer EffectTags;

    UFUNCTION(BlueprintCallable, Category = "Effect")
    virtual bool AddEffect(FGameplayTag EffectTag, AActor* Instigator, AActor* Receptor );
    
    UFUNCTION(BlueprintCallable, Category = "Effect")
    virtual bool RemoveEffect(FGameplayTag EffectTag, AActor* Instigator, AActor* Receptor );
    
    UFUNCTION(BlueprintCallable, Category = "Effect")
    virtual bool OnEffectAdded(FGameplayTag EffectTag, AActor* Instigator, AActor* Receptor );
	
    UFUNCTION(BlueprintCallable, Category = "Effect")
    virtual bool OnEffectRemoved(FGameplayTag EffectTag, AActor* Instigator, AActor* Receptor);
	
    UFUNCTION(BlueprintCallable, Category = "Effect")
    virtual void OnEffectTriggered(FGameplayTag EffectTag, AActor* Instigator, AActor* Receptor);
protected:
    TArray<FASAttributeChangedHolder> AttributeChangedDelegates;
    TArray<FASAttributeAddedHolder> AttributeAddedDelegates;
    TArray<FASAttributeRemovedHolder> AttributeRemovedDelegates;

    int32 NextDelegateID = 0; // Générateur d'ID unique

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
    UUASAttributeSet* DefaultAttributes;
};

USTRUCT()
struct FASAttributeChangedHolder
{
    GENERATED_BODY()

    int32 DelegateID;
    FASAttributeChangeDelegate Delegate;
};

USTRUCT()
struct FASAttributeAddedHolder
{
    GENERATED_BODY()

    int32 DelegateID;
    FASAttributeAddedDelegate Delegate;
};

USTRUCT()
struct FASAttributeRemovedHolder
{
    GENERATED_BODY()

    int32 DelegateID;
    FASAttributeRemovedDelegate Delegate;
};