// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TimerWidget.generated.h"

/**
 * 
 */
UCLASS()
class BLACKHOLEPOWER0_API UTimerWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
	float RemainingTime;
	UFUNCTION(BlueprintCallable, Category = "Event")
	void SetRemainingTime(float NewTime);
};
