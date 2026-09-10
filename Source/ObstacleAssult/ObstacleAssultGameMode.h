// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ObstacleAssultGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AObstacleAssultGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:

	AObstacleAssultGameMode();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	void StartTimer(float DeltaTime);

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> TimerWidgets;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> LevelCompletedWidget;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<UUserWidget> CountDownWidget;

	class UTimerWidget* TimerWidget;

	class ULevelCompleted* LevelCompletedWidgetInstance;

	class UObstacleAssaultGameInstance* ObstacleAssultInstance;

	class UCountDown* CountDownWidgetInstance;

public:
	UPROPERTY(BlueprintReadWrite)
	int32 Timer = 0;

	int32 BestTime = 0;

	float TimeLimit = 0.0f;

	UPROPERTY()
	FString CurrentLevel;

	void LevelCompleted();

	void BestScore();

	UPROPERTY()
	TArray<FString> LevelName;

};



