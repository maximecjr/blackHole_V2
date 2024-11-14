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
		//debug screen getworld time + timer duration + finish time
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("GetWorldTime: %f"), GetWorld()->GetTimeSeconds()));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("TimerDuration: %f"), CurrentGameModeTimer->TimerDuration));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("FinishTime: %f"), FinishTime));
    }
}

float AGameStateTimer::GetCurrentTimestamp() const {
    if (GetWorld()) {
        return GetWorld()->GetTimeSeconds();
    }
    return 0.f;
}
