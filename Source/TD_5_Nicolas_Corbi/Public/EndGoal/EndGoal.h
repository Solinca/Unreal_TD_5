#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EndGoal.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGoalReachedSignature);

UCLASS()
class TD_5_NICOLAS_CORBI_API AEndGoal : public AActor
{
	GENERATED_BODY()
	
protected:
	AEndGoal();

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UBoxComponent> Box = nullptr;

	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:
	UPROPERTY(BlueprintAssignable)
	FOnGoalReachedSignature OnGoalReached;
};
