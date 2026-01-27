#include "Puzzles/LeverPuzzle.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

ALeverPuzzle::ALeverPuzzle()
{
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");

	Root->SetupAttachment(RootComponent);

	RootMesh = CreateDefaultSubobject<UStaticMeshComponent>("Root Mesh");

	RootMesh->SetupAttachment(Root);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Lever");

	Mesh->SetupAttachment(Root);

	Handle = CreateDefaultSubobject<UStaticMeshComponent>("Handle");

	Handle->SetupAttachment(Mesh);

	Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>("Constraint");

	Constraint->SetupAttachment(Root);
}

void ALeverPuzzle::CheckPuzzleCompletion(float DeltaTime)
{
	if (!HasBeenCompletedAlready && Mesh->GetComponentRotation().Yaw < 0)
	{
		OnPuzzleComplete.Broadcast();

		HasBeenCompletedAlready = true;
	}
	else if (HasBeenCompletedAlready && Mesh->GetComponentRotation().Yaw > 0)
	{
		OnPuzzleLocked.Broadcast();

		HasBeenCompletedAlready = false;
	}
}

void ALeverPuzzle::OnFocusGained()
{
	Mesh->SetOverlayMaterial(OutlineMaterial);

	Handle->SetOverlayMaterial(OutlineMaterial);
}

void ALeverPuzzle::OnFocusLost()
{
	Mesh->SetOverlayMaterial(nullptr);

	Handle->SetOverlayMaterial(nullptr);
}
