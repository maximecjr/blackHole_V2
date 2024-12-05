// Fill out your copyright notice in the Description page of Project Settings.


#include "UASWaveSubsystem.h"

#include "FASAIDefaultAttributesDataTable.h"

DEFINE_LOG_CATEGORY(LogMyComponent);

void UUASWaveSubsystem::InitializeAI(UDataTable* DataTable)
{
	if (!DataTable) return;

	const TMap<FName, uint8*>& RowMap = DataTable->GetRowMap();
	for (const auto& Row : RowMap)
	{
		const FFASAIDefaultAttributesDataTable* Attributes = reinterpret_cast<FFASAIDefaultAttributesDataTable*>(Row.Value);
		if (Attributes)
		{
			UE_LOG(LogTemp, Log, TEXT("AI: %s - MaxLife: %f, MaxShield: %f"),
				*Row.Key.ToString(), Attributes->MaxLife, Attributes->MaxShield);
		}
	}
}

