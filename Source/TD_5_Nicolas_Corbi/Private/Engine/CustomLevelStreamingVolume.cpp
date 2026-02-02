#include "Engine/CustomLevelStreamingVolume.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

ACustomLevelStreamingVolume::ACustomLevelStreamingVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	Box = CreateDefaultSubobject<UBoxComponent>("Box");

	Box->SetupAttachment(RootComponent);
}

void ACustomLevelStreamingVolume::BeginPlay()
{
	Super::BeginPlay();

	Box->OnComponentBeginOverlap.AddDynamic(this, &ACustomLevelStreamingVolume::OverlapBegin);

	Box->OnComponentEndOverlap.AddDynamic(this, &ACustomLevelStreamingVolume::OverlapEnd);
}

void ACustomLevelStreamingVolume::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UGameplayStatics::LoadStreamLevel(GetWorld(), LevelToLoad, true, true, FLatentActionInfo{});
}

void ACustomLevelStreamingVolume::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UGameplayStatics::UnloadStreamLevel(GetWorld(), LevelToLoad, FLatentActionInfo{}, true);
}

