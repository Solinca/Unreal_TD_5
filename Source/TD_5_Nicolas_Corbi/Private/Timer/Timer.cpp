#include "Timer/Timer.h"
#include "Puzzles/BasePuzzle.h"

ATimer::ATimer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATimer::BeginPlay()
{
	Super::BeginPlay();

	FirstPuzzle->OnPuzzleComplete.AddDynamic(this, &ATimer::OnFirstPuzzleComplete);

	SecondPuzzle->OnPuzzleComplete.AddDynamic(this, &ATimer::OnSecondPuzzleComplete);

	ThridPuzzle->OnPuzzleComplete.AddDynamic(this, &ATimer::OnThirdPuzzleComplete);
}

void ATimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GlobalTime += DeltaTime;
}

void ATimer::OnFirstPuzzleComplete()
{
	Puzzle1Time = GlobalTime;
}

void ATimer::OnSecondPuzzleComplete()
{
	Puzzle2Time = GlobalTime - Puzzle1Time;
}

void ATimer::OnThirdPuzzleComplete()
{
	Puzzle3Time = GlobalTime - Puzzle2Time;
}
