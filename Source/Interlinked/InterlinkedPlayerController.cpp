// Copyright Epic Games, Inc. All Rights Reserved.


#include "InterlinkedPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "InterlinkedCameraManager.h"

AInterlinkedPlayerController::AInterlinkedPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AInterlinkedCameraManager::StaticClass();
}

void AInterlinkedPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
