// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenu.h"
#include "ConfirmationDialog.h"
#include "ObstacleAssultPlayerController.h"


void UPauseMenu::NativeConstruct()
{
	Super::NativeConstruct();
	
	PlayerController = Cast<AObstacleAssultPlayerController>(GetOwningPlayer());

	if (ConfirmationDialog)
	{
		ConfirmationDialogWidget = CreateWidget<UConfirmationDialog>(GetWorld(), ConfirmationDialog);
		ConfirmationDialogWidget->PauseMenuWidgetInstance = this;
	}
	

	if (ConfirmationDialogWidget)
	{
		ConfirmationDialogWidget->AddToViewport(1);
		ConfirmationDialogWidget->SetVisibility(ESlateVisibility::Hidden);
	}
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
	if (ConfirmationDialogWidget)
	{
		SetVisibility(ESlateVisibility::Hidden);
		ConfirmationDialogWidget->SetVisibility(ESlateVisibility::Visible);
	}
}



