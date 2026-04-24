// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "enemy_mobs.generated.h"

class UAbilitySystemComponent;
class USLCharacterAttributeSet;
struct FTimerHandle;

UCLASS()
class SOULSLIKE_API Aenemy_mobs : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	Aenemy_mobs();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GAS")
	TObjectPtr<USLCharacterAttributeSet> AttributeSet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	float ChaseAcceptanceRadius = 120.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	bool bEnablePlayerChase = true;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI", meta = (ClampMin = 100.0))
	float MaxChaseDistance = 2000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI|Wander")
	bool bEnablePeriodicMove = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI|Wander", meta = (ClampMin = 0.1))
	float PeriodicMoveInterval = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI|Wander", meta = (ClampMin = 100.0))
	float PeriodicMoveRadius = 1000.0f;

	FTimerHandle PeriodicMoveTimer;

	UFUNCTION()
	void MoveToRandomReachableLocation();

public:
	UFUNCTION(BlueprintCallable, Category = "AI")
	float GetChaseAcceptanceRadius() const { return ChaseAcceptanceRadius; }

	UFUNCTION(BlueprintCallable, Category = "AI")
	bool IsPlayerChaseEnabled() const { return bEnablePlayerChase; }

	UFUNCTION(BlueprintCallable, Category = "AI")
	float GetMaxChaseDistance() const { return MaxChaseDistance; }

	UFUNCTION(BlueprintCallable, Category = "AI|Wander")
	void StartPeriodicMove();

	UFUNCTION(BlueprintCallable, Category = "AI|Wander")
	void StopPeriodicMove();
};
