#include "GameStateTimer.h"
#include "Engine/World.h"
#include "GameModeTimer.h"

AGameStateTimer::AGameStateTimer() : Super() {
    
}

void AGameStateTimer::BeginPlay() {
    Super::BeginPlay();

    AGameModeTimer* CurrentGameModeTimer = Cast<AGameModeTimer>(GetWorld()->GetAuthGameMode());
    if (CurrentGameModeTimer) {
        FinishTime = GetWorld()->GetTimeSeconds() + CurrentGameModeTimer->TimerDuration;
    }
    FString TimestampMessage = FString::Printf(TEXT("Timestamp: %f"), FinishTime);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TimestampMessage);
}

float AGameStateTimer::GetCurrentTimestamp() const {
    if (GetWorld()) {
        return GetWorld()->GetTimeSeconds();
    }
    return 0.f;
}
