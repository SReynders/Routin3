// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_controls.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"

void ANPC_controls::BeginPlay() {
	Super::BeginPlay();


	UBlackboardComponent* Temp_BB = nullptr;
	UseBlackboard(NPC_Behave->BlackboardAsset, Temp_BB);

	UBlackboardComponent* NPC_BB = GetBlackboardComponent();

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	NPC_BB->SetValueAsVector(TEXT("PlayerLocation"), PlayerPawn->GetActorLocation());

	RunBehaviorTree(NPC_Behave);
}

void ANPC_controls::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}