#include "Objects/Weight.h"

AWeight::AWeight()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	Mesh->SetupAttachment(RootComponent);
}

void AWeight::BeginPlay()
{
	Super::BeginPlay();

	Mesh->SetMassOverrideInKg(NAME_None, WeightInKg, true);
}

void AWeight::OnFocusGained()
{
	Mesh->SetOverlayMaterial(OutlineMaterial);
}

void AWeight::OnFocusLost()
{
	Mesh->SetOverlayMaterial(nullptr);
}
