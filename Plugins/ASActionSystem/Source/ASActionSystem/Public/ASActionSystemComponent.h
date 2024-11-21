// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Components/ActorComponent.h"
#include "ASAttribute.h"
#include "ASActionSystemComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASACTIONSYSTEM_API UASActionSystemComponent : public UActorComponent
{
    GENERATED_BODY()

private:
    UPROPERTY()
    TArray<FASAttribute> Attributes;

public:
    UASActionSystemComponent();

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
};