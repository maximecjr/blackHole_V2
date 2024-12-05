// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FASAIDefaultAttributesDataTable.generated.h"

/**
 * Structure de données pour la table des attributs par défaut des AIs.
 */
USTRUCT(BlueprintType)
struct ASACTIONSYSTEM_API FFASAIDefaultAttributesDataTable : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float MaxLife;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float MaxShield;
};
