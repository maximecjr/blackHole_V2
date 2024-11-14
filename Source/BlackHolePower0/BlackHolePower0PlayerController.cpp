// Copyright Epic Games, Inc. All Rights Reserved.


#include "BlackHolePower0PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Engine/Engine.h"
#include "TimerHUD.h"
#include "GameStateTimer.h"

ABlackHolePower0PlayerController::ABlackHolePower0PlayerController()
{
    // Activer le Tick
    PrimaryActorTick.bCanEverTick = true;
}
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

    // Délai pour permettre l'initialisation complète de FinishTime
    GetWorld()->GetTimerManager().SetTimerForNextTick([this]()
        {
            AGameStateTimer* CurrentGameState = GetWorld()->GetGameState<AGameStateTimer>();
            if (CurrentGameState)
            {
                EndTimer = CurrentGameState->FinishTime;

                if (EndTimer > 0.0f)
                {
                    // Appeler TriggerEvent ici une fois FinishTime initialisé
                    TriggerEvent(EndTimer);
                }
            }
        });
}

void ABlackHolePower0PlayerController::TriggerEvent(float EndTime)
{
	// Diffuse l'événement avec la valeur du paramètre
	OnTimerSet.Broadcast(EndTime);
}
void ABlackHolePower0PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    // Délai pour permettre l'initialisation complète de FinishTime
    GetWorld()->GetTimerManager().SetTimerForNextTick([this]()
        {
            AGameStateTimer* CurrentGameState = GetWorld()->GetGameState<AGameStateTimer>();
            if (CurrentGameState)
            {
                EndTimer = CurrentGameState->FinishTime;

                if (EndTimer > 0.0f)
                {
                    // Appeler TriggerEvent ici une fois FinishTime initialisé
                    TriggerEvent(EndTimer);
                }
            }
        });
}