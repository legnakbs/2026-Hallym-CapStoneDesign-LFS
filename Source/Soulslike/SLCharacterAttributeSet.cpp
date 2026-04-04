// Fill out your copyright notice in the Description page of Project Settings.


#include "SLCharacterAttributeSet.h"

USLCharacterAttributeSet::USLCharacterAttributeSet() :
	MaxHealth(100.f),
	MaxStamina(100.f),
	MaxMana(40.f),
	MaxPoise(0.f),
	MaxPower(0.f),
	MaxLevel(99.f)
{
	InitHealth(GetMaxHealth());
	InitStamina(GetMaxStamina());
	InitMana(GetMaxMana());
	InitPoise(GetMaxPoise());
	InitPower(GetMaxPower());
	InitLevel(GetMaxLevel());
}

void USLCharacterAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// Clamp Max Values to be always positive 
	if (Attribute == GetMaxHealthAttribute())
	{
		NewValue = FMath::Max(1, NewValue);
	}
	else if (Attribute == GetMaxStaminaAttribute())
	{
		NewValue = FMath::Max(1, NewValue);
	}
	else if (Attribute == GetMaxManaAttribute())
	{
		NewValue = FMath::Max(1, NewValue);
	}
	else if (Attribute == GetMaxPoiseAttribute())
	{
		NewValue = FMath::Max(1, NewValue);
	}
	else if (Attribute == GetMaxPowerAttribute())
	{
		NewValue = FMath::Max(1, NewValue);
	}
	else if (Attribute == GetMaxLevelAttribute())
	{
		NewValue = FMath::Max(1, NewValue);
	}
	// Clamp Values to be always [0~MaxValue]
	else if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxHealth());
	}
	else if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxStamina());
	}
	else if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxMana());
	}
	else if (Attribute == GetPoiseAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxPoise());
	}
	else if (Attribute == GetPowerAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxPower());
	}
	else if (Attribute == GetLevelAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0, GetMaxLevel());
	}
}
