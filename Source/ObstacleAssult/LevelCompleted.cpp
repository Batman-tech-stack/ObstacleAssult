// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelCompleted.h"
#include "ObstacleAssultGameMode.h"
#include "Kismet/GameplayStatics.h"


void ULevelCompleted::NativeConstruct()
{
	Super::NativeConstruct();

	ObstacleAssultGameMode = Cast<AObstacleAssultGameMode>(GetWorld()->GetAuthGameMode());

	PlayerController = GetWorld()->GetFirstPlayerController();	
}

void ULevelCompleted::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	CurrentScoreFunction();

	BestScoreFunction();
}

void ULevelCompleted::CurrentScoreFunction()
{
	if (CurrentScore < ObstacleAssultGameMode->Timer)
	{
		CurrentScore++;
	}
}

void ULevelCompleted::BestScoreFunction()
{
	if (BestScore < ObstacleAssultGameMode->BestTime)
	{
		BestScore++;
	}
}


void ULevelCompleted::MainMenu()
{
	UGameplayStatics::OpenLevel(this, FName("MainMenu"));
}

void ULevelCompleted::SelectLevel(FString LevelName)
{

	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = false;

		FInputModeGameOnly InputMode;
		PlayerController->SetInputMode(InputMode);
	}

	UGameplayStatics::OpenLevel(this, FName(*LevelName));
}




