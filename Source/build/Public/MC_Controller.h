// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MC_Controller.generated.h"

class AMC;

class ANPC;
UCLASS()
class BUILD_API AMC_Controller : public APlayerController
{
	GENERATED_BODY()

protected: virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	virtual void SetupInputComponent();

	virtual void CallForwards(float Value);

	virtual void CallStrafe(float Value);

	virtual void CallLook_Up(float Value);

	virtual void CallTurn(float Value);

	AMC* MyChar;

	UPROPERTY(EditAnywhere)
	ANPC* tempnpc;
};
