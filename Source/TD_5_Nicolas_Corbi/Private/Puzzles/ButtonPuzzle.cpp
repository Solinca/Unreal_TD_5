#include "Puzzles/ButtonPuzzle.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

AButtonPuzzle::AButtonPuzzle()
{
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");

	Root->SetupAttachment(RootComponent);

	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>("Base");

	RootMesh->SetupAttachment(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Button");

	Mesh->SetupAttachment(Root);

	Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>("Constraint");

	Constraint->SetupAttachment(Root);
}

void AButtonPuzzle::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = Mesh->GetComponentLocation();
}

void AButtonPuzzle::CheckPuzzleCompletion(float DeltaTime)
{
	if (!HasBeenCompletedAlready && StartLocation.Z - Mesh->GetComponentLocation().Z > PressedDistanceToConsiderComplete)
	{
		OnPuzzleComplete.Broadcast();

		HasBeenCompletedAlready = true;

		GetWorld()->GetTimerManager().SetTimer(ResetPuzzleTimer, this, &AButtonPuzzle::ResetPuzzle, ResetPuzzleTimerCooldown, false);
	}
}

void AButtonPuzzle::ResetPuzzle()
{
	OnPuzzleLocked.Broadcast();

	HasBeenCompletedAlready = false;
}
