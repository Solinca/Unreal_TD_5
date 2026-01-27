#pragma once

#include "CoreMinimal.h"
#include "Puzzles/BasePuzzle.h"
#include "Interfaces/Interactable.h"
#include "LeverPuzzle.generated.h"

UCLASS()
class TD_5_NICOLAS_CORBI_API ALeverPuzzle : public ABasePuzzle, public IInteractable
{
	GENERATED_BODY()

private:
	bool HasBeenCompletedAlready = false;
	
protected:
	ALeverPuzzle();

	virtual void CheckPuzzleCompletion(float DeltaTime) override;

	virtual void OnFocusGained() override;

	virtual void OnFocusLost() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> RootMesh = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Mesh = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Handle = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UPhysicsConstraintComponent> Constraint = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Material")
	TObjectPtr<UMaterialInstance> OutlineMaterial = nullptr;
};
