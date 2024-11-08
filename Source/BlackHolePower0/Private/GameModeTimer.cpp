#include "GameModeTimer.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h" // Inclusion pour UGameplayStatics
#include "Engine/Engine.h" // Inclusion pour GEngine

AGameModeTimer::AGameModeTimer() : Super() {
    TimerDuration = 10.f;
    
}

void AGameModeTimer::PostLogin(APlayerController* NewPlayer) {
    Super::PostLogin(NewPlayer);
    EndTime = GetWorld()->GetTimeSeconds() + TimerDuration;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AGameModeTimer::OnTimerEnd, TimerDuration, false);
    // debug screen
    if (GEngine) {
    }   
}

void AGameModeTimer::OnTimerEnd() {
    // debug screen
    if (GEngine) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Timer terminé ! Chargement du nouveau niveau..."));
    }
    UGameplayStatics::OpenLevel(GetWorld(), "LevelTitle");
}
