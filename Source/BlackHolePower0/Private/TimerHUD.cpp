// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerHUD.h"
#include "BlackHolePower0/BlackHolePower0PlayerController.h"
void ATimerHUD::BeginPlay() {
	Super::BeginPlay();

	ABlackHolePower0PlayerController* PlayerController = Cast<ABlackHolePower0PlayerController>(GetWorld()->GetFirstPlayerController());	// V�rifie si la classe du widget est d�finie dans l'�diteur
	if (PlayerController) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("lie les deux!"));
		PlayerController->OnTimerSet.AddDynamic(this, &ATimerHUD::OnTimerTriggeredHandler);
	}
	if (TimerWidgetClass) {
		// Cr�e le widget et l'ajoute � l'�cran
		TimerWidgetInstance = CreateWidget<UTimerWidget>(GetWorld(), TimerWidgetClass);
		if (TimerWidgetInstance) {
			TimerWidgetInstance->AddToViewport();
		}
	}
}


void ATimerHUD::OnTimerTriggeredHandler(float EndTime) {
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Re�ois!"));
	if (TimerWidgetInstance) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("mets a jour le temps!"));
		float TempsRestant = EndTime - GetWorld()->GetTimeSeconds();
		TimerWidgetInstance->SetRemainingTime(TempsRestant);
	}
}