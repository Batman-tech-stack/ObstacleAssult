// Fill out your copyright notice in the Description page of Project Settings.


#include "ConfirmationDialog.h"
#include "MainMenuWidget.h"
#include "MainMenuGameMode.h"
#include "Kismet/KismetSystemLibrary.h"

void UConfirmationDialog::NativeConstruct()
{
	Super::NativeConstruct();
	
	MainMenuGameMode = Cast<AMainMenuGameMode>(GetWorld()->GetAuthGameMode());

}

void UConfirmationDialog::YesButtonClicked()
{
	if (MainMenuGameMode)
	{
		UKismetSystemLibrary::QuitGame(this, nullptr, EQuitPreference::Quit, true);
	}
}

void UConfirmationDialog::NoButtonClicked()
{
	if (MainMenuGameMode)
	{
		MainMenuGameMode->MainMenuWidget->SetVisibility(ESlateVisibility::Visible);
		SetVisibility(ESlateVisibility::Hidden);
	}
	
}


