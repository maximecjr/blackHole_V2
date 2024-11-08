// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerHUD.h"
#include "BlackHolePower0/BlackHolePower0PlayerController.h"
void ATimerHUD::BeginPlay() {
	Super::BeginPlay();

	ABlackHolePower0PlayerController* emiteur = Cast<ABlackHolePower0PlayerController>(GetWorld()->SpawnActor<ABlackHolePower0PlayerController>());
}

void ATimerHUD::OnTimerTriggeredHandler() {

}