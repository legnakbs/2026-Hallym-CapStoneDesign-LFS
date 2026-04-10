


#include "SoulslikePlayerState.h"
#include "GameplayAbilitySpec.h"

ASoulslikePlayerState::ASoulslikePlayerState()
{
	asc = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	AttributeSet = CreateDefaultSubobject<USLCharacterAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* ASoulslikePlayerState::GetAbilitySystemComponent() const
{
	return asc;
}

void ASoulslikePlayerState::AddDefaultAbilities()
{
	if (GetLocalRole() != ROLE_Authority || !asc) { return; }

	for (TSubclassOf<UGameplayAbility>& abilityClass : defaultAbilities) {
		if (abilityClass) {
			asc->GiveAbility(FGameplayAbilitySpec(abilityClass, 1));
		}
	}
}
