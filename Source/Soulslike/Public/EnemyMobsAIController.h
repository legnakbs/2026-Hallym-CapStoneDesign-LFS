#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "EnemyMobsAIController.generated.h"

UCLASS()
class SOULSLIKE_API AEnemyMobsAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyMobsAIController();

protected:
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AI")
	float TargetSearchInterval = 0.35f;

private:
	FTimerHandle TargetSearchTimer;
	TWeakObjectPtr<AActor> CachedTargetActor;

	void UpdateChaseTarget();
	AActor* ResolvePlayerTarget() const;
};
