#include "MainMenuGameMode.h"
#include "MainMenuWidget.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"

void AMainMenuGameMode::BeginPlay()
{
    Super::BeginPlay();

    if (MainMenuWidgetClass)
    {

        LevelSelectionWidget = CreateWidget<UMainMenuWidget>(GetWorld(), LevelSelectionWidgetClass);
        MainMenuWidget = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
        
       if (LevelSelectionWidgetClass)
        {
            LevelSelectionWidget->AddToViewport();
            LevelSelectionWidget->SetVisibility(ESlateVisibility::Hidden);
	   }

        if (MainMenuWidget)
        {
            MainMenuWidget->AddToViewport();

            APlayerController* PlayerController =
                GetWorld()->GetFirstPlayerController();

            if (PlayerController)
            {
                PlayerController->bShowMouseCursor = true;

                FInputModeUIOnly InputMode;

                InputMode.SetWidgetToFocus(
                    MainMenuWidget->TakeWidget()
                );

                InputMode.SetLockMouseToViewportBehavior(
                    EMouseLockMode::DoNotLock
                );

                PlayerController->SetInputMode(InputMode);
            }
        }
    }
}