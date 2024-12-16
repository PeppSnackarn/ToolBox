// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHealthSysSig);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PORTFOLIOPIECE1_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	UPROPERTY(EditDefaultsOnly, Category = "Health")
	int MaxHealth = 100;
	UPROPERTY(VisibleAnywhere, Category = "Health")
	int CurrentHealth;
	
	void TakeDamage(int dmg);
	void AddHealth(int value);

	UPROPERTY()
	FHealthSysSig OnDamage;
	UPROPERTY()
	FHealthSysSig OnHeal;
	UPROPERTY()
	FHealthSysSig OnDeath;
};
