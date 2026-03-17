// Fill out your copyright notice in the Description page of Project Settings.


#include "MC_Controller.h"
#include "MC.h"
#include "GameFramework/PlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void AMC_Controller::BeginPlay()
{
	Super::BeginPlay();
	MyChar = Cast<AMC>(GetPawn());
}

void AMC_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMC_Controller::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);
	InputComponent->BindAxis("Move", this, &AMC_Controller::CallForwards);
	InputComponent->BindAxis("Strafe", this, &AMC_Controller::CallStrafe);
	InputComponent->BindAxis("Look", this, &AMC_Controller::CallLook_Up);
	InputComponent->BindAxis("Turn", this, &AMC_Controller::CallTurn);
}

void AMC_Controller::CallForwards(float Value)
{
	if (MyChar) {
		MyChar->Move_Forward(Value);
	}

}

void AMC_Controller::CallStrafe(float Value)
{
	if (MyChar) {
		MyChar->Strafe(Value);
	}
}

void AMC_Controller::CallLook_Up(float Value)
{
	AddPitchInput(Value);

}

void AMC_Controller::CallTurn(float Value)
{

	AddYawInput(Value);
}