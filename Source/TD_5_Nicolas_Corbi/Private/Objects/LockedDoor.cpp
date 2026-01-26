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
}

void ALockedDoor::OnPuzzleLock()
{
	FrontLight->SetLightColor(LockedColor);

	BackLight->SetLightColor(LockedColor);
}

void ALockedDoor::OnPuzzleComplete()
{
	FrontLight->SetLightColor(CompleteColor);

	BackLight->SetLightColor(CompleteColor);
}
