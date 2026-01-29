#pragma once

#include "CoreMinimal.h"
#include "Puzzles/BasePuzzle.h"
#include "ScalePuzzle.generated.h"

UCLASS()
class TD_5_NICOLAS_CORBI_API AScalePuzzle : public ABasePuzzle
{
	GENERATED_BODY()

private:
	int InputWeightInKg = 0;
	
protected:
	AScalePuzzle();

	virtual void BeginPlay() override;

	virtual void CheckPuzzleCompletion(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UStaticMeshComponent> OutputWeight = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UStaticMeshComponent> InputBox = nullptr;
};
