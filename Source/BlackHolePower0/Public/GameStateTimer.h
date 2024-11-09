// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GameStateTimer.generated.h"

/**
 * 
 */
UCLASS()
class BLACKHOLEPOWER0_API AGameStateTimer : public AGameStateBase
{
	GENERATED_BODY()

public:
	// Fonction pour obtenir le temps actuel sous forme de timestamp
	UFUNCTION(BlueprintCallable, Category = "Timer")
	float GetCurrentTimestamp() const;
	
};
