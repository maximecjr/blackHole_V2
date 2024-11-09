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

    UGameInstanceTimer(); // Constructeur pour initialiser LevelToLoad par d�faut

    // Nom du niveau � charger, configurable dans Blueprint
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelTransition")
    FName LevelToLoad;

    // Fonction pour charger le niveau sp�cifi�
    UFUNCTION(BlueprintCallable, Category = "LevelTransition")
    void LoadNewLevel();
};
