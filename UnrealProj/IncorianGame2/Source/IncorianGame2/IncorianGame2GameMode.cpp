// Copyright Epic Games, Inc. All Rights Reserved.

#include "IncorianGame2GameMode.h"
#include "IncorianGame2PlayerController.h"
#include "IncorianGame2Character.h"
#include "UObject/ConstructorHelpers.h"

AIncorianGame2GameMode::AIncorianGame2GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AIncorianGame2PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}