// Fill out your copyright notice in the Description page of Project Settings.

#include "GameStateTimer.h"
#include "Engine/World.h"

float AGameStateTimer::GetCurrentTimestamp() const {
    if (GetWorld()) {
        return GetWorld()->GetTimeSeconds();
    }
    return 0.f;
}
