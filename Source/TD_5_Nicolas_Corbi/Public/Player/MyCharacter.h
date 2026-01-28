#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class TD_5_NICOLAS_CORBI_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	TWeakObjectPtr<AActor> FocusedObjectActor = nullptr;

	TWeakObjectPtr<UPrimitiveComponent> FocusedObjectComponent = nullptr;

	TWeakObjectPtr<UPrimitiveComponent> GrabbedObjectComponent = nullptr;

	FHitResult Hit;

	FCollisionQueryParams Params;

protected:
	AMyCharacter();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UCameraComponent> Camera = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class USpringArmComponent> SpringArm = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USceneComponent> GrabComponent = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<class UPhysicsHandleComponent> PhysicsHandle = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	float MaxGrabDistance = 200.f;

public:
	void FetchFirstPhysicObjectOnSight();

	void ReleaseFetchedObject();
};
