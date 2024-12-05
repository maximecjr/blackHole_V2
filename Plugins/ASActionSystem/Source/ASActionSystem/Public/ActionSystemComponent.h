// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "ActionSystemComponent.generated.h"

class UAbility;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASACTIONSYSTEM_API UActionSystemComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UActionSystemComponent();

    // Ajout et suppression d'abilities
    UFUNCTION(BlueprintCallable, Category = "Abilities")
    bool AddAbility(UAbility* Ability, AActor* Instigator);

    UFUNCTION(BlueprintCallable, Category = "Abilities")
    bool RemoveAbility(FGameplayTag AbilityTag, AActor* Instigator);

    UFUNCTION(BlueprintCallable, Category = "Abilities")
    void TriggerAbility(FGameplayTag AbilityTag, AActor* Instigator);

private:
    // Liste des abilities attachées
    UPROPERTY()
    TArray<UAbility*> Abilities;
};
