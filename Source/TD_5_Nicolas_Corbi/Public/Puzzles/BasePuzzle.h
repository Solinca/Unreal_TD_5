#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BasePuzzle.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPuzzleCompleteSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPuzzleLockedSignature);

UCLASS()
class TD_5_NICOLAS_CORBI_API ABasePuzzle : public AActor
{
	GENERATED_BODY()
	
protected:
	ABasePuzzle();

	virtual void Tick(float DeltaTime) override;

	virtual void CheckPuzzleCompletion(float DeltaTime) {};

public:
	FOnPuzzleCompleteSignature OnPuzzleComplete;

	FOnPuzzleLockedSignature OnPuzzleLocked;
};
