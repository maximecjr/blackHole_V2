// Copyright Epic Games, Inc. All Rights Reserved.


#include "BlackHolePower0PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Engine/Engine.h"

void ABlackHolePower0PlayerController::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("constr."));

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);


	}
}
void ABlackHolePower0PlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}
void ABlackHolePower0PlayerController::TriggerEvent(float EndTime)
{
	// Diffuse l'événement avec la valeur du paramètre
	OnTimerSet.Broadcast(EndTime);
}