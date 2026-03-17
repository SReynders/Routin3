// Fill out your copyright notice in the Description page of Project Settings.


#include "MC.h"
#include "NPC.h"
#include "MC_Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SceneCaptureComponent2D.h"
// Sets default values
AMC::AMC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
}

// Called when the game starts or when spawned
void AMC::BeginPlay()
{
	Super::BeginPlay();
	ControllerRef = GetController();
}

// Called every frame
void AMC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMC::Move_Forward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

void AMC::Strafe(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AMC::Look_Up(float Value)
{
	AddControllerPitchInput(Value);
}

void AMC::Turn(float Value)
{
	AddControllerYawInput(Value);
}
