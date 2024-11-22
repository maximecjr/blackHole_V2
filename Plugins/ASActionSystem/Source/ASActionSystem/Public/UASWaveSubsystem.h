// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "UASWaveSubsystem.generated.h"

/**
 * 
 */
DECLARE_LOG_CATEGORY_EXTERN(LogMyComponent, Log, All);
UCLASS()
class ASACTIONSYSTEM_API UUASWaveSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	void InitializeAI(UDataTable* Data);
	
};
