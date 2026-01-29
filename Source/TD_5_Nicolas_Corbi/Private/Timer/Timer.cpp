#include "Timer/Timer.h"
#include "Puzzles/BasePuzzle.h"
#include "Components/TextRenderComponent.h"

ATimer::ATimer()
{
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");

	Root->SetupAttachment(RootComponent);

	CongratulationText = CreateDefaultSubobject<UTextRenderComponent>("CongratulationText");

	CongratulationText->SetupAttachment(Root);

	FirstPuzzleTimerText = CreateDefaultSubobject<UTextRenderComponent>("FirstPuzzleTimerText");

	FirstPuzzleTimerText->SetupAttachment(Root);

	SecondPuzzleTimerText = CreateDefaultSubobject<UTextRenderComponent>("SecondPuzzleTimerText");

	SecondPuzzleTimerText->SetupAttachment(Root);

	ThirdPuzzleTimerText = CreateDefaultSubobject<UTextRenderComponent>("ThirdPuzzleTimerText");

	ThirdPuzzleTimerText->SetupAttachment(Root);

	LineText = CreateDefaultSubobject<UTextRenderComponent>("LineText");

	LineText->SetupAttachment(Root);

	GlobalTimerText = CreateDefaultSubobject<UTextRenderComponent>("GlobalTimerText");

	GlobalTimerText->SetupAttachment(Root);
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
	Puzzle3Time = GlobalTime - Puzzle1Time - Puzzle2Time;

	CongratulationText->SetText(FText::FromString("Congratulations!"));

	FirstPuzzleTimerText->SetText(FText::FromString(FString::Printf(TEXT("First Puzzle Time: %.2f s"), Puzzle1Time)));

	SecondPuzzleTimerText->SetText(FText::FromString(FString::Printf(TEXT("Second Puzzle Time: %.2f s"), Puzzle2Time)));

	ThirdPuzzleTimerText->SetText(FText::FromString(FString::Printf(TEXT("Thrid Puzzle Time: %.2f s"), Puzzle3Time)));

	LineText->SetText(FText::FromString("-----------------"));

	GlobalTimerText->SetText(FText::FromString(FString::Printf(TEXT("Global Time: %.2f s"), Puzzle1Time + Puzzle2Time + Puzzle3Time)));
}
