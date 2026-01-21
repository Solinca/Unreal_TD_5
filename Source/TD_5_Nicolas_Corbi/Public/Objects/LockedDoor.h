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
	void OnPuzzleLock();

	UFUNCTION()
	void OnPuzzleComplete();
	
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
	TObjectPtr<class UPointLightComponent> Light = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	FLinearColor LockedColor = FLinearColor(1, 0, 0);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	FLinearColor CompleteColor = FLinearColor(0, 1, 0);
};
