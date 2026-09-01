// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerWidget.h"
#include "ObstacleAssultGameMode.h"

void UTimerWidget::NativeConstruct()
{
	Super::NativeConstruct();

	GameMode = Cast<AObstacleAssultGameMode>(GetWorld()->GetAuthGameMode());
}

void UTimerWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	
		DisplayTime = GameMode->Timer;
	
}
