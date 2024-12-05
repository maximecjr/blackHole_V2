// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "Ability.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ASACTIONSYSTEM_API UAbility : public UObject
{
    GENERATED_BODY()

public:
    // Tags associés à l'ability
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
    FGameplayTag AbilityTag;

    // Events Blueprint
    UFUNCTION(BlueprintNativeEvent, Category = "Ability")
    void OnAbilityAdded(AActor* Instigator);

    UFUNCTION(BlueprintNativeEvent, Category = "Ability")
    void OnAbilityRemoved(AActor* Instigator);

    UFUNCTION(BlueprintNativeEvent, Category = "Ability")
    void Start(AActor* Instigator);

    UFUNCTION(BlueprintNativeEvent, Category = "Ability")
    void Stop(AActor* Instigator);

    UFUNCTION(BlueprintNativeEvent, Category = "Ability")
    bool CanStartAbility(AActor* Instigator) const;

    UFUNCTION(BlueprintNativeEvent, Category = "Ability")
    bool CanAddAbility(AActor* Instigator) const;

};
