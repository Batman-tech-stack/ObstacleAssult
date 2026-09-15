// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleAssaultGameInstance.h"
#include "ObstacleAssaultSaveGame.h"
#include "Kismet/GameplayStatics.h"

UObstacleAssaultGameInstance::UObstacleAssaultGameInstance()
{
    BestTime.SetNum(3);

    for (int32 i = 0; i < BestTime.Num(); i++)
    {
        BestTime[i] = 0.0f;
    }
}

void UObstacleAssaultGameInstance::Init()
{
    Super::Init();

    LoadGame();
}

void UObstacleAssaultGameInstance::SaveGame()
{
	UObstacleAssaultSaveGame* SaveObject =
		Cast<UObstacleAssaultSaveGame>(
			UGameplayStatics::CreateSaveGameObject(
				UObstacleAssaultSaveGame::StaticClass()
			)
		);

	if (SaveObject)
	{
		SaveObject->BestTime = BestTime;

		UGameplayStatics::SaveGameToSlot(
			SaveObject,
			TEXT("PlayerSave"),
			0
		);
	}
}

void UObstacleAssaultGameInstance::LoadGame()
{
	if (UGameplayStatics::DoesSaveGameExist(TEXT("PlayerSave"), 0))
	{
		UObstacleAssaultSaveGame* SaveObject =
			Cast<UObstacleAssaultSaveGame>(
				UGameplayStatics::LoadGameFromSlot(
					TEXT("PlayerSave"),
					0
				)
			);

		if (SaveObject)
		{
			BestTime = SaveObject->BestTime;
		}
	}
}