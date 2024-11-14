// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerHUD.h"
#include "BlackHolePower0/BlackHolePower0PlayerController.h"
void ATimerHUD::BeginPlay() {
	Super::BeginPlay();

	ABlackHolePower0PlayerController* PlayerController = Cast<ABlackHolePower0PlayerController>(GetWorld()->GetFirstPlayerController());	// Vérifie si la classe du widget est définie dans l'éditeur
	if (PlayerController) {
		PlayerController->OnTimerSet.AddDynamic(this, &ATimerHUD::OnTimerTriggeredHandler);
	}
	if (TimerWidgetClass) {
		// Crée le widget et l'ajoute à l'écran
		TimerWidgetInstance = CreateWidget<UTimerWidget>(GetWorld(), TimerWidgetClass);
		if (TimerWidgetInstance) {
			TimerWidgetInstance->AddToViewport();
		}
	}
}


void ATimerHUD::OnTimerTriggeredHandler(float EndTime) {
	if (TimerWidgetInstance) {
		float TempsRestant = EndTime - GetWorld()->GetTimeSeconds();
		TimerWidgetInstance->SetRemainingTime(TempsRestant);
	}
}