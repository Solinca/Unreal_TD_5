#include "EndGoal/EndGoal.h"
#include "Kismet/GameplayStatics.h"
#include "Player/MyPlayerController.h"
#include "Components/BoxComponent.h"

AEndGoal::AEndGoal()
{
	PrimaryActorTick.bCanEverTick = false;

	Box = CreateDefaultSubobject<UBoxComponent>("Box");
}

void AEndGoal::BeginPlay()
{
	Super::BeginPlay();

	Box->OnComponentBeginOverlap.AddDynamic(this, &AEndGoal::OverlapBegin);
}

void AEndGoal::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (AMyPlayerController* MyPC = Cast<AMyPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0)))
	{
		MyPC->OnGoalReached();

		OnGoalReached.Broadcast();
	}
}
