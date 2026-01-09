// Copyright Epic Games, Inc. All Rights Reserved.

#include "buildGameMode.h"
#include "buildCharacter.h"
#include "UObject/ConstructorHelpers.h"

AbuildGameMode::AbuildGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
