#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Interactable.h"
#include "Weight.generated.h"

UCLASS()
class TD_5_NICOLAS_CORBI_API AWeight : public AActor, public IInteractable
{
	GENERATED_BODY()
	
protected:
	AWeight();

	virtual void BeginPlay() override;

	virtual void OnFocusGained() override;

	virtual void OnFocusLost() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UStaticMeshComponent> Mesh = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Material")
	TObjectPtr<UMaterialInstance> OutlineMaterial = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Settings")
	int WeightInKg = 0;

public:
	int GetWeightInKg() { return WeightInKg; };
};
