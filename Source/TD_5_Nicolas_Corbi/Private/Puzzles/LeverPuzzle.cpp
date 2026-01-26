#include "Puzzles/LeverPuzzle.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

ALeverPuzzle::ALeverPuzzle()
{
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");

	Root->SetupAttachment(RootComponent);

	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>("Root Mesh");

	RootMesh->SetupAttachment(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Lever");

	Mesh->SetupAttachment(RootMesh);

	Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>("Constraint");

	Constraint->SetupAttachment(RootMesh);
}

void ALeverPuzzle::BeginPlay()
{
	Super::BeginPlay();
}

void ALeverPuzzle::CheckPuzzleCompletion(float DeltaTime)
{

}
