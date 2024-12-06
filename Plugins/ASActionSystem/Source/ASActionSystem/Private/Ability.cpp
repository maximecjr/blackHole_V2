// Fill out your copyright notice in the Description page of Project Settings.


#include "Ability.h"
#include "GameFramework/Actor.h"

void UAbility::OnAbilityAdded_Implementation(AActor* Instigator)
{
    // Par d�faut : aucun comportement
    UE_LOG(LogTemp, Log, TEXT("Ability [%s] added to Instigator [%s]"), *GetClass()->GetName(), *Instigator->GetName());
}

void UAbility::OnAbilityRemoved_Implementation(AActor* Instigator)
{
    // Par d�faut : aucun comportement
    UE_LOG(LogTemp, Log, TEXT("Ability [%s] removed from Instigator [%s]"), *GetClass()->GetName(), *Instigator->GetName());
}

void UAbility::Start_Implementation(AActor* Instigator, UWorld* World)
{
    // Par d�faut : aucun comportement
    UE_LOG(LogTemp, Log, TEXT("Ability [%s] started by Instigator [%s]"), *GetClass()->GetName(), *Instigator->GetName());
}

void UAbility::Stop_Implementation(AActor* Instigator)
{
    // Par d�faut : aucun comportement
    UE_LOG(LogTemp, Log, TEXT("Ability [%s] stopped by Instigator [%s]"), *GetClass()->GetName(), *Instigator->GetName());
}

bool UAbility::CanStartAbility_Implementation(AActor* Instigator) const
{
    // Par d�faut : Toujours vrai
    return true;
}

bool UAbility::CanAddAbility_Implementation(AActor* Instigator) const
{
    // Par d�faut : Toujours vrai
    return true;
}
