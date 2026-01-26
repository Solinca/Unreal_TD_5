#include "Player/MyCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

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

	DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Camera, Params))
	{
		FocusedObject = Hit.GetComponent();
	}
	else
	{
		FocusedObject = nullptr;
	}

	if (GrabbedObject)
	{
		PhysicsHandle->SetTargetLocationAndRotation(End, GrabComponent->GetComponentRotation());
	}
}

void AMyCharacter::FetchFirstPhysicObjectOnSight()
{
	if (FocusedObject)
	{
		GrabbedObject = FocusedObject;

		PhysicsHandle->GrabComponentAtLocation(GrabbedObject, "", GrabbedObject->GetComponentLocation());
	}
}

void AMyCharacter::ReleaseFetchedObject()
{
	PhysicsHandle->ReleaseComponent();

	GrabbedObject = nullptr;
}
