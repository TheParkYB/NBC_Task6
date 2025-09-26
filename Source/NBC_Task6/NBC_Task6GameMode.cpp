// Copyright Epic Games, Inc. All Rights Reserved.

#include "NBC_Task6GameMode.h"
#include "NBC_Task6Character.h"
#include "UObject/ConstructorHelpers.h"

ANBC_Task6GameMode::ANBC_Task6GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
