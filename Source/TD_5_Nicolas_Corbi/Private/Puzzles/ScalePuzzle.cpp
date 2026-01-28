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
}
