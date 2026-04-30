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

/**
 * Centralized gameplay tag names for the combat system. Resolved via
 * FGameplayTag::RequestGameplayTag at call time — the tags must exist in the
 * project's tag table (DefaultGameplayTags.ini or equivalent).
 */
namespace SLCombatTags
{
	// SetByCaller magnitude tag used by USLGE_WeaponDamage. The caller (weapon /
	// ability) sets this to the final damage value before applying the spec.
	static const FName SetByCaller_DamageBase = TEXT("Data.Damage.Base");

	// SetByCaller magnitude tag for poise damage. Same pattern as Damage.
	static const FName SetByCaller_PoiseDamage = TEXT("Data.Damage.Poise");

	// SetByCaller magnitude tag for stamina cost. USLGE_StaminaCost reads this and
	// subtracts it from the Stamina attribute.
	static const FName SetByCaller_StaminaCost = TEXT("Data.Cost.Stamina");

	// State tags applied during dodge / invulnerability windows. Other abilities
	// query / block on these (e.g. attack abilities cancelled by State.Dodging,
	// damage GEs short-circuit on State.Invulnerable).
	static const FName State_Dodging = TEXT("State.Dodging");
	static const FName State_Invulnerable = TEXT("State.Invulnerable");

	// Activation tag for the dodge ability — character input maps to this.
	static const FName Activate_Dodge = TEXT("PlayerAbility.Dodge");
}
