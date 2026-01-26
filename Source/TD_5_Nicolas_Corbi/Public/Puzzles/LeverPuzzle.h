#pragma once

#include "CoreMinimal.h"
#include "Puzzles/BasePuzzle.h"
#include "LeverPuzzle.generated.h"

UCLASS()
class TD_5_NICOLAS_CORBI_API ALeverPuzzle : public ABasePuzzle
{
	GENERATED_BODY()
	
protected:
	ALeverPuzzle();

	virtual void BeginPlay() override;

	virtual void CheckPuzzleCompletion(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> RootMesh = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Mesh = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UPhysicsConstraintComponent> Constraint = nullptr;
};
