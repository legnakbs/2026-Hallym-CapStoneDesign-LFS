#include "enemy_mobs.h"
#include "AbilitySystemComponent.h"
#include "SLCharacterAttributeSet.h"
#include "EnemyMobsAIController.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "TimerManager.h"

Aenemy_mobs::Aenemy_mobs()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<USLCharacterAttributeSet>(TEXT("AttributeSet"));

	AIControllerClass = AEnemyMobsAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	bUseControllerRotationYaw = false;
}

UAbilitySystemComponent* Aenemy_mobs::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void Aenemy_mobs::BeginPlay()
{
	Super::BeginPlay();
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	Tags.AddUnique(FName("Enemy"));

	if (bEnablePeriodicMove)
	{
		StartPeriodicMove();
	}
}

void Aenemy_mobs::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	StopPeriodicMove();
	Super::EndPlay(EndPlayReason);
}

void Aenemy_mobs::StartPeriodicMove()
{
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().SetTimer(
			PeriodicMoveTimer,
			this,
			&Aenemy_mobs::MoveToRandomReachableLocation,
			PeriodicMoveInterval,
			true);
	}
}

void Aenemy_mobs::StopPeriodicMove()
{
	if (UWorld* World = GetWorld())
	{
		World->GetTimerManager().ClearTimer(PeriodicMoveTimer);
	}
}

void Aenemy_mobs::MoveToRandomReachableLocation()
{
	AAIController* AIController = Cast<AAIController>(GetController());
	if (!AIController)
	{
		return;
	}

	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
	if (!NavSystem)
	{
		return;
	}

	FNavLocation RandomLocation;
	const bool bFound = NavSystem->GetRandomReachablePointInRadius(GetActorLocation(), PeriodicMoveRadius, RandomLocation);
	if (!bFound)
	{
		return;
	}

	AIController->MoveToLocation(RandomLocation.Location, ChaseAcceptanceRadius, true, true, true, false, nullptr, true);
}
