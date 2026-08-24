// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"
#include "ObstacleAssultPlayerController.h"


void UPauseMenu::NativeConstruct()
{
	Super::NativeConstruct();

	PlayerController = Cast<AObstacleAssultPlayerController>(GetOwningPlayer());
}

void UPauseMenu::ResumeGame()
{
	if (PlayerController)
	{
		PlayerController->PauseGame();
	}
}

void UPauseMenu::MainMenu()
{
}

void UPauseMenu::QuitGame()
{
}


