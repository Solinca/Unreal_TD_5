#include "Objects/Weight.h"

AWeight::AWeight()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	Mesh->SetupAttachment(RootComponent);
}

void AWeight::OnFocusGained()
{
	Mesh->SetOverlayMaterial(OutlineMaterial);
}

void AWeight::OnFocusLost()
{
	Mesh->SetOverlayMaterial(nullptr);
}
