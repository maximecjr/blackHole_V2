#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UASAttributeSet.generated.h"

// Structure pour stocker les données des attributs
USTRUCT(BlueprintType)
struct FASAttributeData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FGameplayTag AttributeTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float DefaultValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float MinValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float MaxValue;
};

/**
 * DataAsset pour stocker les attributs par défaut
 */
UCLASS(Blueprintable)
class ASACTIONSYSTEM_API UUASAttributeSet : public UDataAsset
{
	GENERATED_BODY()

public:
	// Tableau d'attributs par défaut
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Attributes")
	TArray<FASAttributeData> Attributes;
};
