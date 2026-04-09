


#include "SoulslikePlayerState.h"

ASoulslikePlayerState::ASoulslikePlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));

	AttributeSet = CreateDefaultSubobject<USLCharacterAttributeSet>(TEXT("AttributeSet"));
}

UAbilitySystemComponent* ASoulslikePlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
