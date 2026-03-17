// Fill out your copyright notice in the Description page of Project Settings.


#include "NormalGame.h"
#include "NPC_controls.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/TargetPoint.h"
#include "MC_Controller.h"
#include "MC.h"
#include "NPC.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTree.h"

ANormalGame::ANormalGame() {
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

//enum state for the calculation of the stage of the game to further set up te logic for the start , win and lose menus
enum GameState { StartMenu, Playing, Win, Lose };
GameState CurrentState = StartMenu;
//basic allocation of values to further help with the functions below
void ANormalGame::BeginPlay()
{
	CurrentState = StartMenu;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);
	PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	ControllerRef = PlayerPawn->GetController();
}

void ANormalGame::Tick(float DeltaTime)
{

}

void ANormalGame::StartGame()
{
	CurrentState = Playing;
	Change();
}

void ANormalGame::Change()
{
	if (CurrentState == StartMenu) {
		Cast<AMC_Controller>(ControllerRef)->SetShowMouseCursor(true);
		FInputModeUIOnly inputui;
		Cast<AMC_Controller>(ControllerRef)->SetInputMode(inputui);
		UGameplayStatics::SetGamePaused(GetWorld(), true);

	}

	if (CurrentState == Playing) {

		Cast<AMC_Controller>(ControllerRef)->SetShowMouseCursor(false);
		FInputModeGameOnly inputgame;
		Cast<AMC_Controller>(ControllerRef)->SetInputMode(inputgame);
		UGameplayStatics::SetGamePaused(GetWorld(), false);
		//remove main menu widgets//
	}
}