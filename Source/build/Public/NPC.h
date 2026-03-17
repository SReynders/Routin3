// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPC.generated.h"


class UCameraComponent;
class USpringArmComponent;

UCLASS()
class BUILD_API ANPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC();

	void Move_Forward(float Value);
	UFUNCTION()
	void Strafe(float Value);
	UFUNCTION()
	void Look_Up(float Value);
	UFUNCTION()
	void Turn(float Value);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	AController* ControllerRef;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:

	UPROPERTY(VisibleAnywhere);
	UStaticMeshComponent* staticmesh;

	FVector Direction;

	FVector turn;

	FVector CameraLocation;

	FRotator CameraRotation;

	UPROPERTY(EditAnywhere);
	UCameraComponent* Camera;
	UPROPERTY(EditAnywhere);
	USpringArmComponent* SpringArm;
};
