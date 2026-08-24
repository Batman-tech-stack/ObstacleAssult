// Copyright Epic Games, Inc. All Rights Reserved.

#include "ObstacleAssultPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "Widgets/Input/SVirtualJoystick.h"
#include "ObstacleAssult.h"


AObstacleAssultPlayerController::AObstacleAssultPlayerController()
{
	// Allow the PlayerController to continue ticking while paused.
	bShouldPerformFullTickWhenPaused = true;
}


void AObstacleAssultPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Create pause menu
	if (PauseMenuWidget)
	{
		PauseMenu = CreateWidget<UUserWidget>(this, PauseMenuWidget);

		if (PauseMenu)
		{
			// Add it to the screen but keep it hidden initially.
			PauseMenu->AddToViewport(10);
			PauseMenu->SetVisibility(ESlateVisibility::Hidden);

			UE_LOG(LogObstacleAssult, Warning, TEXT("Pause Menu Created Successfully"));
		}
		else
		{
			UE_LOG(LogObstacleAssult, Error, TEXT("Failed to create Pause Menu"));
		}
	}
	else
	{
		UE_LOG(LogObstacleAssult, Error, TEXT("PauseMenuWidget is NOT assigned!"));
	}


	// Spawn mobile controls only for local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		MobileControlsWidget = CreateWidget<UUserWidget>(
			this,
			MobileControlsWidgetClass
		);

		if (MobileControlsWidget)
		{
			MobileControlsWidget->AddToPlayerScreen(0);
		}
		else
		{
			UE_LOG(
				LogObstacleAssult,
				Error,
				TEXT("Could not spawn mobile controls widget.")
			);
		}
	}
}


void AObstacleAssultPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();


	// Bind Enhanced Input actions
	if (UEnhancedInputComponent* EnhancedInputComponent =
		Cast<UEnhancedInputComponent>(InputComponent))
	{
		if (PauseAction)
		{
			EnhancedInputComponent->BindAction(
				PauseAction,
				ETriggerEvent::Started,
				this,
				&AObstacleAssultPlayerController::PauseGame
			);
		}
		else
		{
			UE_LOG(
				LogObstacleAssult,
				Error,
				TEXT("PauseAction is NOT assigned!")
			);
		}
	}


	// Only add mapping contexts for local player controllers
	if (IsLocalPlayerController())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem =
			ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(
				GetLocalPlayer()))
		{
			// Add default mapping contexts
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				if (CurrentContext)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}


			// Add mobile-excluded mappings when not using touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext :
					MobileExcludedMappingContexts)
				{
					if (CurrentContext)
					{
						Subsystem->AddMappingContext(CurrentContext, 0);
					}
				}
			}
		}
	}
}


void AObstacleAssultPlayerController::PauseGame()
{
	// Make sure the pause menu exists
	if (!PauseMenu)
	{
		UE_LOG(
			LogObstacleAssult,
			Error,
			TEXT("PauseMenu is NULL!")
		);

		return;
	}


	// If game is currently paused → RESUME
	if (IsPaused())
	{
		SetPause(false);

		PauseMenu->SetVisibility(ESlateVisibility::Hidden);

		ResumeInputModeGameOnly();

		UE_LOG(
			LogObstacleAssult,
			Warning,
			TEXT("GAME RESUMED")
		);
	}

	// If game is currently running → PAUSE
	else
	{
		SetPause(true);

		PauseMenu->SetVisibility(ESlateVisibility::Visible);

		PauseInputModeUIOnly();

		UE_LOG(
			LogObstacleAssult,
			Warning,
			TEXT("GAME PAUSED")
		);
	}
}


void AObstacleAssultPlayerController::PauseInputModeUIOnly()
{
	bShowMouseCursor = true;

	FInputModeGameAndUI InputMode;

	InputMode.SetWidgetToFocus(
		PauseMenu->TakeWidget()
	);

	InputMode.SetLockMouseToViewportBehavior(
		EMouseLockMode::DoNotLock
	);

	SetInputMode(InputMode);
}


void AObstacleAssultPlayerController::ResumeInputModeGameOnly()
{
	bShowMouseCursor = false;

	FInputModeGameOnly InputMode;

	SetInputMode(InputMode);
}