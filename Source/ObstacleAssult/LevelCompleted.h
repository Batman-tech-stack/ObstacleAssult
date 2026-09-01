// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LevelCompleted.generated.h"

/**
 * 
 */
UCLASS()
class OBSTACLEASSULT_API ULevelCompleted : public UUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	class AObstacleAssultGameMode* ObstacleAssultGameMode;
	
	void CurrentScoreFunction();

	void BestScoreFunction();

	class APlayerController* PlayerController;


public:

	UPROPERTY(BlueprintReadOnly)
	int32 CurrentScore;

	UPROPERTY(BlueprintReadOnly)
	int32 BestScore;

	UFUNCTION(BlueprintCallable)
	void MainMenu();

	UFUNCTION(BlueprintCallable)
	void SelectLevel(FString LevelName);


};
