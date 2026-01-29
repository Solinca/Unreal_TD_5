#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Timer.generated.h"

UCLASS()
class TD_5_NICOLAS_CORBI_API ATimer : public AActor
{
	GENERATED_BODY()

private:
	float GlobalTime = 0;

	float Puzzle1Time;

	float Puzzle2Time;

	float Puzzle3Time;

	UFUNCTION()
	void OnFirstPuzzleComplete();

	UFUNCTION()
	void OnSecondPuzzleComplete();

	UFUNCTION()
	void OnThirdPuzzleComplete();
	
protected:
	ATimer();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Puzzles")
	TObjectPtr<class ABasePuzzle> FirstPuzzle = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Puzzles")
	TObjectPtr<class ABasePuzzle> SecondPuzzle = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Puzzles")
	TObjectPtr<class ABasePuzzle> ThridPuzzle = nullptr;
};
