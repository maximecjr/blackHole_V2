#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeTimer.generated.h"

UCLASS()
class BLACKHOLEPOWER0_API AGameModeTimer : public AGameModeBase
{
    GENERATED_BODY()

public:
    // Dur�e du Timer en secondes
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
    float TimerDuration;

    // Heure de fin du Timer
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Timer")
    float EndTime;

    // Handle pour g�rer le Timer
    FTimerHandle TimerHandle;

    // Constructeur
    AGameModeTimer();

protected:
    // Fonction appel�e quand un joueur se connecte
    virtual void PostLogin(APlayerController* NewPlayer) override;

    // Fonction appel�e � la fin du Timer
    UFUNCTION()
    void OnTimerEnd();
};
