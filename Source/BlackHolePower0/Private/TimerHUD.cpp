// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerHUD.h"
#include "BlackHolePower0/BlackHolePower0PlayerController.h"
void ATimerHUD::BeginPlay() {
	Super::BeginPlay();

	ABlackHolePower0PlayerController* PlayerController = Cast<ABlackHolePower0PlayerController>(GetWorld()->GetFirstPlayerController());	// Vérifie si la classe du widget est définie dans l'éditeur
	// debug screen controller name
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, PlayerController->GetName());
	if (PlayerController) {
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("lie les deux!"));
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
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Reçois!"));
	if (TimerWidgetInstance) {
		// debug screen EndTime
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("EndTime: %f"), EndTime));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("mets a jour le temps!"));
		float TempsRestant = EndTime - GetWorld()->GetTimeSeconds();
		TimerWidgetInstance->SetRemainingTime(TempsRestant);
	}
}