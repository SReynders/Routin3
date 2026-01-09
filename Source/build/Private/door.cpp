#include "door.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
Adoor::Adoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create root component
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// Create static mesh component for the door
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootComponent);

	// Initialize door state
	bIsOpen = false;
	bIsRotating = false;
}

// Called when the game starts or when spawned
void Adoor::BeginPlay()
{
	Super::BeginPlay();

	// Store the initial closed rotation
	ClosedRotation = GetActorRotation();
}

// Called every frame
void Adoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Handle smooth door rotation
	if (bIsRotating)
	{
		FRotator CurrentRotation = GetActorRotation();
		FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, RotationSpeed);
		SetActorRotation(NewRotation);

		// Check if we've reached the target rotation (within 1 degree tolerance)
		if (CurrentRotation.Equals(TargetRotation, 1.0f))
		{
			bIsRotating = false;
		}
	}
}

void Adoor::Interact()
{
	// Toggle door state
	bIsOpen = !bIsOpen;

	if (bIsOpen)
	{
		// Rotate 90 degrees on Y axis to open
		TargetRotation = ClosedRotation + FRotator(0.0f, 90.0f, 0.0f);
	}
	else
	{
		// Return to original rotation to close
		TargetRotation = ClosedRotation;
	}

	// Start the rotation animation
	bIsRotating = true;
}