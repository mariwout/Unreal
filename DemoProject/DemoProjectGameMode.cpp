// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "DemoProjectGameMode.h"
#include "DemoProjectPlayerController.h"
#include "DemoProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADemoProjectGameMode::ADemoProjectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ADemoProjectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}