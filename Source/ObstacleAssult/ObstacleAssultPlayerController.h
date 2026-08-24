// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ObstacleAssultPlayerController.generated.h"

class UInputMappingContext;
class UUserWidget;
class UInputAction;

/**
 * Basic PlayerController class for a third person game
 * Manages input mappings and pause menu
 */
UCLASS(abstract)
class AObstacleAssultPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AObstacleAssultPlayerController();

	/** Toggle pause/resume */
	void PauseGame();

protected:

	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category = "Input|Input Mappings")
	TArray<UInputMappingContext*> MobileExcludedMappingContexts;

	/** Mobile controls widget to spawn */
	UPROPERTY(EditAnywhere, Category = "Input|Touch Controls")
	TSubclassOf<UUserWidget> MobileControlsWidgetClass;

	/** Pointer to the mobile controls widget */
	UPROPERTY()
	TObjectPtr<UUserWidget> MobileControlsWidget;

	/** Pause input action */
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> PauseAction;

	/** Pause menu widget class */
	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<UUserWidget> PauseMenuWidget;

	/** Created pause menu widget */
	UPROPERTY()
	TObjectPtr<UUserWidget> PauseMenu;

	/** Set input mode to UI */
	void PauseInputModeUIOnly();

	/** Set input mode back to game */
	void ResumeInputModeGameOnly();
};