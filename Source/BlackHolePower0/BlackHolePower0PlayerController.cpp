// Copyright Epic Games, Inc. All Rights Reserved.


#include "BlackHolePower0PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Engine/Engine.h"
#include "GameStateTimer.h"

void ABlackHolePower0PlayerController::BeginPlay()
{
	Super::BeginPlay();

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
	AGameStateTimer* CurrentGameState = GetWorld()->GetGameState<AGameStateTimer>();
	EndTimer = CurrentGameState->FinishTime;
	TriggerEvent(EndTimer);
}
void ABlackHolePower0PlayerController::TriggerEvent(float EndTime)
{
	if (OnTimerSet.IsBound()) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("lie!"));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("pas lie!"));
	}
	// Diffuse l'événement avec la valeur du paramètre
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Broadcast!"));
	OnTimerSet.Broadcast(EndTime);
}