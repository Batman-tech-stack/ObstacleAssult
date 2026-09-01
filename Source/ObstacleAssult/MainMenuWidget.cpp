// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "ObstacleAssaultGameInstance.h"
#include "ConfirmationDialog.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "MainMenuGameMode.h"


void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	MainMenuGameMode = Cast<AMainMenuGameMode>(GetWorld()->GetAuthGameMode());
	ObstacleAssultInstance = Cast<UObstacleAssaultGameInstance>(UGameplayStatics::GetGameInstance(this));

	if (MainMenuGameMode)
	{
		MainWidget = MainMenuGameMode->MainMenuWidget;

		LevelSelectionWidget = MainMenuGameMode->LevelSelectionWidget;
	}

	if (ObstacleAssultInstance)
	{
		for (int i = 0; i < 3; i++)
		{
			BestTimeWidget[i] = ObstacleAssultInstance->BestTime[i];
		}
	}
}

void UMainMenuWidget::OpenLevel()
{
	UE_LOG(LogTemp, Warning, TEXT("START GAME WAS CALLED"));

	APlayerController* PlayerController =
		GetWorld()->GetFirstPlayerController();

	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = false;

		FInputModeGameOnly InputMode;
		PlayerController->SetInputMode(InputMode);
	}

	UGameplayStatics::OpenLevel(this, FName(*LevelName));
}

void UMainMenuWidget::StartGame()
{
	LevelSelectionWidget->SetVisibility(ESlateVisibility::Visible);
	MainWidget->SetVisibility(ESlateVisibility::Hidden);
}


void UMainMenuWidget::QuitGame()
{
	MainMenuGameMode->ConfirmationDialogWidget->SetVisibility(ESlateVisibility::Visible);
	SetVisibility(ESlateVisibility::Hidden);
}

void UMainMenuWidget::BackButton()
{
	MainWidget->SetVisibility(ESlateVisibility::Visible);
	LevelSelectionWidget->SetVisibility(ESlateVisibility::Hidden);
}

