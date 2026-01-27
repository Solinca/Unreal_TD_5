#pragma once

#include "CoreMinimal.h"
#include "Puzzles/BasePuzzle.h"
#include "ButtonPuzzle.generated.h"

UCLASS()
class TD_5_NICOLAS_CORBI_API AButtonPuzzle : public ABasePuzzle
{
	GENERATED_BODY()

private:
	FTimerHandle ResetPuzzleTimer;

	FVector StartLocation;

	bool HasBeenCompletedAlready = false;
	
protected:
	AButtonPuzzle();

	virtual void BeginPlay() override;

	virtual void CheckPuzzleCompletion(float DeltaTime) override;

	void ResetPuzzle();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> RootMesh = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Mesh = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UPhysicsConstraintComponent> Constraint = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	float PressedDistanceToConsiderComplete = 10.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	float ResetPuzzleTimerCooldown = 2.f;
};
