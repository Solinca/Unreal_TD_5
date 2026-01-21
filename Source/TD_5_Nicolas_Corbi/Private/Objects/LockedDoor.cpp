#include "Objects/LockedDoor.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/PointLightComponent.h"

ALockedDoor::ALockedDoor()
{
	PrimaryActorTick.bCanEverTick = false;

	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");

	Root->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	Mesh->SetupAttachment(Root);

	Light = CreateDefaultSubobject<UPointLightComponent>("Light");

	Light->SetupAttachment(Mesh);

	FirstConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>("First Constraint");

	FirstConstraint->SetupAttachment(Root);

	SecondConstraint = CreateDefaultSubobject<UPhysicsConstraintComponent>("Second Constraint");

	SecondConstraint->SetupAttachment(Root);
}

void ALockedDoor::BeginPlay()
{
	Super::BeginPlay();
}

void ALockedDoor::OnPuzzleLock()
{
	Light->SetLightColor(LockedColor);
}

void ALockedDoor::OnPuzzleComplete()
{
	Light->SetLightColor(CompleteColor);
}
