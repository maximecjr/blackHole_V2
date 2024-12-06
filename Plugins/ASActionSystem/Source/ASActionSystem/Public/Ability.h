// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "Ability.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityTriggered, AActor*, Instigator);


UCLASS(Blueprintable, BlueprintType)
class ASACTIONSYSTEM_API UAbility : public UObject
{
    GENERATED_BODY()

public:
    // Tags associés à l'ability
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
    FGameplayTag AbilityTag;

    // Délégué pour déclencher des effets (ex. lancer une boule de feu)
    UPROPERTY(BlueprintAssignable, Category = "Ability")
    FOnAbilityTriggered OnAbilityTriggered;

    // Events Blueprint
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
    void OnAbilityAdded(AActor* Instigator);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
    void OnAbilityRemoved(AActor* Instigator);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
    void Start(AActor* Instigator, UWorld* World);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
    void Stop(AActor* Instigator);

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable,Category = "Ability")
    bool CanStartAbility(AActor* Instigator) const;

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Ability")
    bool CanAddAbility(AActor* Instigator) const;

};
