#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomLevelStreamingVolume.generated.h"

UCLASS()
class TD_5_NICOLAS_CORBI_API ACustomLevelStreamingVolume : public AActor
{
	GENERATED_BODY()
	
protected:
	ACustomLevelStreamingVolume();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UBoxComponent> Box = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	TObjectPtr<UWorld> LevelToLoad = nullptr;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
