// Fill out your copyright notice in the Description page of Project Settings.

#include "GameInstanceTimer.h"
#include "Kismet/GameplayStatics.h"

UGameInstanceTimer::UGameInstanceTimer() {
    // nom du niveau par défaut
    LevelToLoad = FName("LevelTitle"); 
}

void UGameInstanceTimer::LoadNewLevel() {
    if (GetWorld() && !LevelToLoad.IsNone()) {  // Vérification que LevelToLoad est configuré
        UGameplayStatics::OpenLevel(GetWorld(), LevelToLoad);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Le nom du niveau à charger n'est pas défini !"));
    }
}
