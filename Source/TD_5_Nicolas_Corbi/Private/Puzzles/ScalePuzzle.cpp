#include "Puzzles/ScalePuzzle.h"
#include "Components/BoxComponent.h"

AScalePuzzle::AScalePuzzle()
{
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");

	Root->SetupAttachment(RootComponent);

	InputBox = CreateDefaultSubobject<UStaticMeshComponent>("Input Box");

	InputBox->SetupAttachment(Root);

	OutputWeight = CreateDefaultSubobject<UStaticMeshComponent>("Output Weight");

	OutputWeight->SetupAttachment(Root);
}

void AScalePuzzle::BeginPlay()
{
	Super::BeginPlay();

	int DesiredWeight = FMath::RandRange(1, 20);

	OutputWeight->SetMassOverrideInKg(NAME_None, DesiredWeight * 100, true);
}

void AScalePuzzle::CheckPuzzleCompletion(float DeltaTime)
{
	if (!HasBeenCompletedAlready && FMath::IsNearlyEqual(InputBox->GetComponentLocation().Z, OutputWeight->GetComponentLocation().Z, 15))
	{
		OnPuzzleComplete.Broadcast();

		HasBeenCompletedAlready = true;
	}
	else if (HasBeenCompletedAlready && !FMath::IsNearlyEqual(InputBox->GetComponentLocation().Z, OutputWeight->GetComponentLocation().Z, 15))
	{
		OnPuzzleLocked.Broadcast();

		HasBeenCompletedAlready = false;
	}
}
