#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LockedDoor.generated.h"

UCLASS()
class TD_5_NICOLAS_CORBI_API ALockedDoor : public AActor
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnPuzzleComplete();

	UFUNCTION()
	void OnPuzzleLocked();
	
protected:
	ALockedDoor();
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Mesh = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UPhysicsConstraintComponent> FirstConstraint = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UPhysicsConstraintComponent> SecondConstraint = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UPointLightComponent> FrontLight = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UPointLightComponent> BackLight = nullptr;

	UPROPERTY(EditAnywhere, Category = "Puzzle")
	TObjectPtr<class ABasePuzzle> Puzzle = nullptr;

	UPROPERTY(EditAnywhere, Category = "Sound")
	TObjectPtr<class USoundBase> LockedSound = nullptr;

	UPROPERTY(EditAnywhere, Category = "Sound")
	TObjectPtr<class USoundBase> UnlockedSound = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	FLinearColor LockedColor = FLinearColor(1, 0, 0);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	FLinearColor CompleteColor = FLinearColor(0, 1, 0);
};
