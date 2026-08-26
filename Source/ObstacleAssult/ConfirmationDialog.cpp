// Fill out your copyright notice in the Description page of Project Settings.


#include "ConfirmationDialog.h"
#include "PauseMenu.h"
#include "MainMenuWidget.h"
#include "MainMenuGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UConfirmationDialog::NativeConstruct()
{
	Super::NativeConstruct();
	if (MainMenuGameMode)
	{
		MainMenuGameMode = Cast<AMainMenuGameMode>(GetWorld()->GetAuthGameMode());
	}
	
}

void UConfirmationDialog::YesButtonClicked()
{
	if (MainMenuGameMode)
	{
		UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
	}

	if (PauseMenuWidgetInstance)
	{
		UGameplayStatics::OpenLevel(this, FName("MainMenu"));
	}
}

void UConfirmationDialog::NoButtonClicked()
{
	if (MainMenuGameMode)
	{
		MainMenuGameMode->MainMenuWidget->SetVisibility(ESlateVisibility::Visible);
		SetVisibility(ESlateVisibility::Hidden);
	}

	if (PauseMenuWidgetInstance)
	{
		PauseMenuWidgetInstance->SetVisibility(ESlateVisibility::Visible);
		SetVisibility(ESlateVisibility::Hidden);
	}
	
}


