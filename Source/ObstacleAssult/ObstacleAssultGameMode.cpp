// Copyright Epic Games, Inc. All Rights Reserved.

#include "ObstacleAssultGameMode.h"
#include "CountDown.h"
#include "TimerWidget.h"
#include "LevelCompleted.h"
#include "ObstacleAssaultGameInstance.h"
#include "Kismet/GameplayStatics.h"

AObstacleAssultGameMode::AObstacleAssultGameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AObstacleAssultGameMode::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	CountDownWidgetInstance = CreateWidget<UCountDown>(GetWorld(), CountDownWidget);

	if (CountDownWidgetInstance)
	{
		CountDownWidgetInstance->AddToViewport(2);
		CountDownWidgetInstance->SetVisibility(ESlateVisibility::Visible);
		PlayerController->SetIgnoreMoveInput(true);
		PlayerController->SetIgnoreLookInput(true);

		PlayerController->bShowMouseCursor = false;

		FInputModeGameOnly InputMode;
		PlayerController->SetInputMode(InputMode);

		UGameplayStatics::SetGamePaused(GetWorld(), true);
		
	}

	TimerWidget = CreateWidget<UTimerWidget>(GetWorld(), TimerWidgets);
	ObstacleAssultInstance = Cast<UObstacleAssaultGameInstance>(UGameplayStatics::GetGameInstance(this));
	LevelCompletedWidgetInstance = CreateWidget<ULevelCompleted>(GetWorld(), LevelCompletedWidget);	

	if(LevelCompletedWidgetInstance)
	{
		LevelCompletedWidgetInstance->AddToViewport(1);
		LevelCompletedWidgetInstance->SetVisibility(ESlateVisibility::Hidden);
	}

	if (TimerWidget)
	{
		TimerWidget->AddToViewport(0);
		TimerWidget->SetVisibility(ESlateVisibility::Visible);
	}

	LevelName = { "MainLevel","MainLevel2","MainLevel3" };

	CurrentLevel = UGameplayStatics::GetCurrentLevelName(this);


	for (int i = 0; i < LevelName.Num(); i++)
	{
		if (CurrentLevel == LevelName[i])
		{
			  BestTime = ObstacleAssultInstance->BestTime[i];
		}
	}

}

void AObstacleAssultGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	StartTimer(DeltaTime);

	
}
void AObstacleAssultGameMode::StartTimer(float DeltaTime)
{
	TimeLimit += DeltaTime;

	if (TimeLimit >= 1.0f)
	{
		Timer++;
		TimeLimit -= 1.0f;
	}

	
}

void AObstacleAssultGameMode::LevelCompleted()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController)
	{
		SetPause(PlayerController);

		PlayerController->bShowMouseCursor = true;

		FInputModeGameAndUI InputMode;
		PlayerController->SetInputMode(InputMode);

	}

	BestScore();

	

	for (int i = 0; i < LevelName.Num(); i++)
	{
		if (CurrentLevel == LevelName[i])
		{
			ObstacleAssultInstance->BestTime[i] = BestTime;

			ObstacleAssultInstance->SaveGame();
		}
	}

	LevelCompletedWidgetInstance->SetVisibility(ESlateVisibility::Visible);
}

void AObstacleAssultGameMode::BestScore()
{
	if (BestTime == 0 || Timer < BestTime)
	{
		BestTime = Timer;
	}
}
