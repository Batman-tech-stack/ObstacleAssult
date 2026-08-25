// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ConfirmationDialog.generated.h"

/**
 * 
 */

class AMainMenuGameMode;

UCLASS()
class OBSTACLEASSULT_API UConfirmationDialog : public UUserWidget
{
	GENERATED_BODY()


	UPROPERTY()
	TObjectPtr<AMainMenuGameMode> MainMenuGameMode;

protected:

	virtual void NativeConstruct() override;


public:
	UFUNCTION(BlueprintCallable)
	void YesButtonClicked();

	UFUNCTION(BlueprintCallable)
	void NoButtonClicked();
};
