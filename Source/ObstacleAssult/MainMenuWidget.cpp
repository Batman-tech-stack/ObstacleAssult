// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	MainMenuGameMode = Cast<AMainMenuGameMode>(GetWorld()->GetAuthGameMode());

	if (MainMenuGameMode)
	{
		MainWidget = MainMenuGameMode->MainMenuWidget;

		LevelSelectionWidget = MainMenuGameMode->LevelSelectionWidget;
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
	UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
}

void UMainMenuWidget::BackButton()
{
	MainWidget->SetVisibility(ESlateVisibility::Visible);
	LevelSelectionWidget->SetVisibility(ESlateVisibility::Hidden);
}

