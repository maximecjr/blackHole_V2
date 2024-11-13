#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TimerWidget.h"
#include "BlackHolePower0/BlackHolePower0PlayerController.h"
#include "TimerHUD.generated.h"

/**
 *
 */
UCLASS()
class BLACKHOLEPOWER0_API ATimerHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	void OnTimerTriggeredHandler(float EndTime);

protected:
	// Référence vers le widget du timer
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<UTimerWidget> TimerWidgetClass;

public:
	// Instance du widget
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	UTimerWidget* TimerWidgetInstance;
};
