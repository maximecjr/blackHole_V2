#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GameStateTimer.generated.h"

UCLASS()
class BLACKHOLEPOWER0_API AGameStateTimer : public AGameStateBase
{
    GENERATED_BODY()

public:
    AGameStateTimer();  // Déclare le constructeur

    virtual void BeginPlay() override;

    float GetCurrentTimestamp() const;

private:
    float FinishTime;
};