#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeTimer.generated.h"

UCLASS()
class BLACKHOLEPOWER0_API AGameModeTimer : public AGameModeBase
{
    GENERATED_BODY()

public:
    // Durée du Timer en secondes
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
    float TimerDuration;

    // Heure de fin du Timer
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Timer")
    float EndTime;

    // Handle pour gérer le Timer
    FTimerHandle TimerHandle;

    // Constructeur
    AGameModeTimer();

protected:
    // Fonction appelée quand un joueur se connecte
    virtual void PostLogin(APlayerController* NewPlayer) override;

    // Fonction appelée à la fin du Timer
    UFUNCTION()
    void OnTimerEnd();
};
