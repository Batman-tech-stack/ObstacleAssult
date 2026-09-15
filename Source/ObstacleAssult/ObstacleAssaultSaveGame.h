#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "ObstacleAssaultSaveGame.generated.h"

UCLASS()
class OBSTACLEASSULT_API UObstacleAssaultSaveGame : public USaveGame
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TArray<float> BestTime;
};