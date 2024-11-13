// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BlackHolePower0PlayerController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimerSet, float, EndTime);

class UInputMappingContext;

/**
 *
 */
UCLASS()
class BLACKHOLEPOWER0_API ABlackHolePower0PlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Begin Actor interface
public:

	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* InPawn) override;

	// End Actor interface
	// Déclare la variable delegate en tant qu'événement Blueprint
	UPROPERTY(BlueprintAssignable, Category = "Event")
	FOnTimerSet OnTimerSet;

	// Fonction pour déclencher l'événement
	UFUNCTION(BlueprintCallable, Category = "Event")
	void TriggerEvent(float EndTime);
public:
	float EndTimer;
};
