#include "Player/MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Interfaces/Interactable.h"

AMyCharacter::AMyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");

	SpringArm->SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	Camera->SetupAttachment(SpringArm);

	GrabComponent = CreateDefaultSubobject<USceneComponent>("Grab Component");

	GrabComponent->SetupAttachment(Camera);

	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>("Physics Handle");
}

void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	Params = {};

	Params.AddIgnoredActors(TArray<AActor*> { this });
}

void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Start = GrabComponent->GetComponentLocation();

	FVector End = GrabComponent->GetForwardVector() * MaxGrabDistance + Start;

	if (GrabbedObjectComponent.IsValid())
	{
		PhysicsHandle->SetTargetLocation(End);
	}
	else
	{
		if (FocusedObjectActor.IsValid())
		{
			Cast<IInteractable>(FocusedObjectActor)->OnFocusLost();
		}

		if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Camera, Params) && Hit.GetActor()->Implements<UInteractable>())
		{
			FocusedObjectComponent = Hit.GetComponent();

			FocusedObjectActor = Hit.GetActor();

			Cast<IInteractable>(FocusedObjectActor)->OnFocusGained();
		}
		else
		{
			FocusedObjectActor = nullptr;

			FocusedObjectComponent = nullptr;
		}
	}
}

void AMyCharacter::FetchFirstPhysicObjectOnSight()
{
	if (FocusedObjectComponent.IsValid())
	{
		GrabbedObjectComponent = FocusedObjectComponent;

		PhysicsHandle->GrabComponentAtLocation(GrabbedObjectComponent.Get(), "", GrabbedObjectComponent->GetComponentLocation());
	}
}

void AMyCharacter::ReleaseFetchedObject()
{
	PhysicsHandle->ReleaseComponent();

	GrabbedObjectComponent = nullptr;
}
