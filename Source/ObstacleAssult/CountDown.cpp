// Fill out your copyright notice in the Description page of Project Settings.

#include "CountDown.h"
#include "Kismet/GameplayStatics.h"

void UCountDown::NativeConstruct()
{
    Super::NativeConstruct();

    CurrentCountDownTime = 0.0f;
    bCountdownFinished = false;

    PlayerController = GetWorld()->GetFirstPlayerController();
}

void UCountDown::NativeTick(
    const FGeometry& MyGeometry,
    float InDeltaTime
)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    StartCountDown(InDeltaTime);
}

void UCountDown::StartCountDown(float DeltaTime)
{
    if (bCountdownFinished)
    {
        return;
    }

    if (CountDownTime > 0)
    {
        CurrentCountDownTime += DeltaTime;

        if (CurrentCountDownTime >= 1.0f)
        {
            CurrentCountDownTime = 0.0f;
            CountDownTime--;

            // You can update your countdown TextBlock here
            // Example:
            // CountdownText->SetText(FText::AsNumber(CountDownTime));
        }
    }
    else
    {
        bCountdownFinished = true;

        // Enable player controls
        if (PlayerController)
        {
            PlayerController->SetIgnoreMoveInput(false);
            PlayerController->SetIgnoreLookInput(false);

            PlayerController->bShowMouseCursor = false;

            FInputModeGameOnly InputMode;
            PlayerController->SetInputMode(InputMode);
        }

        // Resume game
        UGameplayStatics::SetGamePaused(GetWorld(), false);

        // Hide countdown
        SetVisibility(ESlateVisibility::Hidden);
    }
}