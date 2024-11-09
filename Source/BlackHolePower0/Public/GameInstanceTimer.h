// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameInstanceTimer.generated.h"

/**
 * 
 */
UCLASS()
class BLACKHOLEPOWER0_API UGameInstanceTimer : public UGameInstance
{
	GENERATED_BODY()

public:

    UGameInstanceTimer(); // Constructeur pour initialiser LevelToLoad par défaut

    // Nom du niveau à charger, configurable dans Blueprint
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelTransition")
    FName LevelToLoad;

    // Fonction pour charger le niveau spécifié
    UFUNCTION(BlueprintCallable, Category = "LevelTransition")
    void LoadNewLevel();
};
