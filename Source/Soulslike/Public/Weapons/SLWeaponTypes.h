#pragma once

#include "CoreMinimal.h"
#include "SLWeaponTypes.generated.h"

/** Weapon category — drives animations, stance, and which ability set gets granted. */
UENUM(BlueprintType)
enum class ESLWeaponCategory : uint8
{
	None		UMETA(DisplayName = "None"),
	Straight	UMETA(DisplayName = "Straight Sword"),
	Great		UMETA(DisplayName = "Greatsword"),
	Dagger		UMETA(DisplayName = "Dagger"),
	Axe			UMETA(DisplayName = "Axe"),
	Spear		UMETA(DisplayName = "Spear"),
	Bow			UMETA(DisplayName = "Bow"),
	Staff		UMETA(DisplayName = "Staff"),
	Shield		UMETA(DisplayName = "Shield")
};

/** Which hand / slot the weapon occupies when equipped. */
UENUM(BlueprintType)
enum class ESLWeaponSlot : uint8
{
	MainHand	UMETA(DisplayName = "Main Hand"),
	OffHand		UMETA(DisplayName = "Off Hand"),
	TwoHanded	UMETA(DisplayName = "Two Handed")
};

/** Damage typing used to multiply against enemy resistances. */
UENUM(BlueprintType)
enum class ESLDamageType : uint8
{
	Physical	UMETA(DisplayName = "Physical"),
	Slash		UMETA(DisplayName = "Slash"),
	Pierce		UMETA(DisplayName = "Pierce"),
	Blunt		UMETA(DisplayName = "Blunt"),
	Fire		UMETA(DisplayName = "Fire"),
	Frost		UMETA(DisplayName = "Frost"),
	Lightning	UMETA(DisplayName = "Lightning"),
	Dark		UMETA(DisplayName = "Dark")
};
