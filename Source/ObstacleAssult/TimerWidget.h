// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TimerWidget.generated.h"

/**
 * 
 */
UCLASS()
class OBSTACLEASSULT_API UTimerWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	virtual void NativeConstruct() override;

	virtual	 void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	class AObstacleAssultGameMode* GameMode;
		
public:

	UPROPERTY(BlueprintReadWrite, Category = "Time")
	float DisplayTime = 0.0f;

};
