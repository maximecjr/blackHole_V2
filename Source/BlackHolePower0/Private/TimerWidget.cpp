// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerWidget.h"
#include "Engine/Engine.h"  // N�cessaire pour GEngine

void UTimerWidget::SetRemainingTime(float NewTime) {
	RemainingTime = NewTime;
}