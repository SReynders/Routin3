#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "door.generated.h"

UCLASS()
class BUILD_API Adoor : public AActor
{
    GENERATED_BODY()

public:
    Adoor();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // Static Mesh component for the door
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    class UStaticMeshComponent* DoorMesh;

    // Function to interact with the door
    UFUNCTION(BlueprintCallable, Category = "Door")
    void Interact();

private:
    bool bIsOpen;
    FRotator TargetRotation;
    FRotator ClosedRotation;

    UPROPERTY(EditAnywhere, Category = "Door")
    float RotationSpeed = 2.0f;

    bool bIsRotating;
};