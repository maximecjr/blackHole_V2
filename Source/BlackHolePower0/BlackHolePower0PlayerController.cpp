// Copyright Epic Games, Inc. All Rights Reserved.


#include "BlackHolePower0PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Engine/Engine.h"
#include "TimerHUD.h"
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

    // D�lai pour permettre l'initialisation compl�te de FinishTime
    GetWorld()->GetTimerManager().SetTimerForNextTick([this]()
        {
            AGameStateTimer* CurrentGameState = GetWorld()->GetGameState<AGameStateTimer>();
            if (CurrentGameState)
            {
                EndTimer = CurrentGameState->FinishTime;

                if (EndTimer > 0.0f)
                {
                    // Appeler TriggerEvent ici une fois FinishTime initialis�
                    TriggerEvent(EndTimer);
                }
                else
                {
                    GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("FinishTime nest toujours pas initialise."));
                }
            }
        });
}

void ABlackHolePower0PlayerController::TriggerEvent(float EndTime)
{
	if (OnTimerSet.IsBound()) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("lie!"));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("pas lie!"));
	}
	// Diffuse l'�v�nement avec la valeur du param�tre
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Broadcast!"));
	OnTimerSet.Broadcast(EndTime);
}