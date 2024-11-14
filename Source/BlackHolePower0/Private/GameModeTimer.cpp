#include "GameModeTimer.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h" // Inclusion pour UGameplayStatics
#include "GameStateTimer.h"
#include "GameInstanceTimer.h"
#include "Engine/Engine.h" // Inclusion pour GEngine

AGameModeTimer::AGameModeTimer() : Super() {
    TimerDuration = 10.f;
    
}

void AGameModeTimer::PostLogin(APlayerController* NewPlayer) {
    Super::PostLogin(NewPlayer);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("postlogin"));
    float CurrentTime = GetWorld()->GetTimeSeconds();

    if (AGameStateTimer* CurrentGameState = GetWorld()->GetGameState<AGameStateTimer>()) {
        CurrentTime = CurrentGameState->GetCurrentTimestamp();
        UE_LOG(LogTemp, Log, TEXT("Current Timestamp: %f"), CurrentTime);
    }

    EndTime = CurrentTime + TimerDuration;
    GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AGameModeTimer::OnTimerEnd, TimerDuration, false);
}


void AGameModeTimer::OnTimerEnd() {

    if (UGameInstanceTimer* GameInstance = Cast<UGameInstanceTimer>(GetGameInstance())) {
        GameInstance->LoadNewLevel();
    }
}
