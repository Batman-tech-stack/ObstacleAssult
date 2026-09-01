// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleAssaultGameInstance.h"

UObstacleAssaultGameInstance::UObstacleAssaultGameInstance()
{
    BestTime.SetNum(3);

    for (int32 i = 0; i < BestTime.Num(); i++)
    {
        BestTime[i] = 0.0f;
    }
}