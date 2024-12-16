// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "UGameplayEffect.generated.h"

/**
 * 
 */
// Enumération pour les opérations sur les attributs
UENUM(BlueprintType)
enum class EAttributeOperation : uint8
{
	Add UMETA(DisplayName = "Add"),
	Subtract UMETA(DisplayName = "Subtract"),
	Multiply UMETA(DisplayName = "Multiply"),
	Divide UMETA(DisplayName = "Divide")
};

// Structure pour les modificateurs d'attributs
USTRUCT(BlueprintType)
struct FAttributeModifier
{
	GENERATED_BODY()

	// Valeur du modificateur
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Value;

	// Tag de l'attribut ciblé
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag TargetAttribute;

	// Opération appliquée à l'attribut
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EAttributeOperation Operation;
};

UCLASS(Blueprintable,BlueprintType)
class ASACTIONSYSTEM_API UUGameplayEffect : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
	FGameplayTag EffectTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
	float Duree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
	float periode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
	FGameplayTagContainer AddedTags;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
	FGameplayTagContainer BlockedTags;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Effect")
	TArray<FAttributeModifier> AttributeModifiers;

	
	
};
