#pragma once

#include "CoreMinimal.h"
#include "Ability.h"
#include "AbilityBlackHole.generated.h"

class ABlackHolePower0Projectile;

UCLASS(Blueprintable, BlueprintType)
class ASACTIONSYSTEM_API UAbilityBlackHole : public UAbility
{
	GENERATED_BODY()

public:
	// Classe du projectile à spawner
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability|Black Hole")
	TSubclassOf<ABlackHolePower0Projectile> ProjectileClass;

	// Surcharge de l'événement Start
	virtual void Start_Implementation(AActor* Instigator, UWorld* World) override;

protected:
	// Fonction pour spawner le projectile
	void SpawnBlackHoleProjectile(AActor* Instigator);
};
