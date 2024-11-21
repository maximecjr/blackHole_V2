// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "GameplayTagContainer.h"
#include "ASAttribute.generated.h"

USTRUCT(BlueprintType)
struct FASAttribute
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
    FGameplayTag AttributeTag;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
    float CurrentValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
    float MaxValue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attribute")
    float MinValue;

    FASAttribute()
        : CurrentValue(0.0f), MaxValue(0.0f), MinValue(0.0f) {}
};