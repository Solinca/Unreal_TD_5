#include "Objects/LockedDoor.h"
#include "Puzzles/BasePuzzle.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/PointLightComponent.h"

ALockedDoor::ALockedDoor()
{
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");

	Root->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	Mesh->SetupAttachment(Root);

	FrontLight = CreateDefaultSubobject<UPointLightComponent>("Front Light");

	FrontLight->SetupAttachment(Mesh);

	BackLight = CreateDefaultSubobject<UPointLightComponent>("Back Light");

	BackLight->SetupAttachment(Mesh);

	FirstConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>("First Constraint");

	FirstConstraint->SetupAttachment(Root);

	SecondConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>("Second Constraint");

	SecondConstraint->SetupAttachment(Root);
}

void ALockedDoor::BeginPlay()
{
	Super::BeginPlay();

	if (Puzzle)
	{
		Puzzle->OnPuzzleComplete.AddDynamic(this, &ALockedDoor::OnPuzzleComplete);

		Puzzle->OnPuzzleLocked.AddDynamic(this, &ALockedDoor::OnPuzzleLocked);
	}

	OnPuzzleLocked();
}

void ALockedDoor::OnPuzzleComplete()
{
	FrontLight->SetLightColor(CompleteColor);
		
	BackLight->SetLightColor(CompleteColor);

	FirstConstraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Limited, 90);

	SecondConstraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Limited, 90);
}

void ALockedDoor::OnPuzzleLocked()
{
	FrontLight->SetLightColor(LockedColor);

	BackLight->SetLightColor(LockedColor);

	FirstConstraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 90);

	SecondConstraint->SetAngularSwing1Limit(EAngularConstraintMotion::ACM_Locked, 90);
}
