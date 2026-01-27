#include "Puzzles/BasePuzzle.h"

ABasePuzzle::ABasePuzzle()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABasePuzzle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckPuzzleCompletion(DeltaTime);
}
