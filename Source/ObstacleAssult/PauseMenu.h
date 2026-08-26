// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenu.generated.h"

/**
 * 
 */

class AObstacleAssultPlayerController;

UCLASS()

class OBSTACLEASSULT_API UPauseMenu : public UUserWidget
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	void ResumeGame();

	UFUNCTION(BlueprintCallable)
	void MainMenu();

	UPROPERTY()
	TObjectPtr<AObstacleAssultPlayerController> PlayerController;

protected:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<class UUserWidget> ConfirmationDialog;

public:

	UPROPERTY()
	class UConfirmationDialog* ConfirmationDialogWidget;
};
