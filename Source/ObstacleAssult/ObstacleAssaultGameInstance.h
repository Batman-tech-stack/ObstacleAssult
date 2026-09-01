// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ObstacleAssaultGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class OBSTACLEASSULT_API UObstacleAssaultGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:

	UObstacleAssaultGameInstance();

	UPROPERTY()
	TArray<float> BestTime;
};
