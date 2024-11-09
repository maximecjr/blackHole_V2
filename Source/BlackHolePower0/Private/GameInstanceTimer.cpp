// Fill out your copyright notice in the Description page of Project Settings.

#include "GameInstanceTimer.h"
#include "Kismet/GameplayStatics.h"

UGameInstanceTimer::UGameInstanceTimer() {
    // nom du niveau par d�faut
    LevelToLoad = FName("LevelTitle"); 
}

void UGameInstanceTimer::LoadNewLevel() {
    if (GetWorld() && !LevelToLoad.IsNone()) {  // V�rification que LevelToLoad est configur�
        UGameplayStatics::OpenLevel(GetWorld(), LevelToLoad);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Le nom du niveau � charger n'est pas d�fini !"));
    }
}
