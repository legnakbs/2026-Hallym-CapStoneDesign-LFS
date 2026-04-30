#include "Abilities/SLGE_StaminaRegen.h"

#include "SLCharacterAttributeSet.h"
#include "Weapons/SLWeaponTypes.h"

USLGE_StaminaRegen::USLGE_StaminaRegen()
{
	DurationPolicy = EGameplayEffectDurationType::Infinite;

	// Tick 10 times per second; 5 stamina per tick = 50/sec — fast Sekiro-ish recovery.
	Period = 0.1f;
	bExecutePeriodicEffectOnApplication = false;

	FGameplayModifierInfo Mod;
	Mod.Attribute = USLCharacterAttributeSet::GetStaminaAttribute();
	Mod.ModifierOp = EGameplayModOp::Additive;
	Mod.ModifierMagnitude = FScalableFloat(5.f);
	Modifiers.Add(Mod);

	// Pause regen ticks while the target is spending stamina. The tag is set in
	// USLCharacterAttributeSet::PostGameplayEffectExecute and cleared on a timer.
	const FGameplayTag SpendingTag = FGameplayTag::RequestGameplayTag(SLCombatTags::State_StaminaSpending, /*ErrorIfNotFound*/ false);
	if (SpendingTag.IsValid())
	{
		OngoingTagRequirements.IgnoreTags.AddTag(SpendingTag);
	}
}
