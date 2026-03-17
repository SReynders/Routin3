// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC_controls.generated.h"

class ATargetPoint;
class UBehaviorTree;

UCLASS()
class BUILD_API ANPC_controls : public AAIController
{
	GENERATED_BODY()
	

public:
	/*void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UBehaviorTree* NPC_Behave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	UBlackboardData* BlackboardAsset;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY()
	TArray<AActor*> Waypoints;




};
