// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"


void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = MaxHealth;
}

void UHealthComponent::TakeDamage(int dmg)
{
	CurrentHealth -= dmg;
	if(CurrentHealth <= 0 && OnDeath.IsBound())
	{
		OnDeath.Broadcast();
		return;
	}
	if(OnDamage.IsBound())
		OnDamage.Broadcast();
}

void UHealthComponent::AddHealth(int value)
{
	if(CurrentHealth != MaxHealth)
	{
		CurrentHealth -= value;
		if(OnHeal.IsBound())
			OnHeal.Broadcast();
	}
}
