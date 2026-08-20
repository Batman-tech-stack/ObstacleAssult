// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "MainMenuGameMode.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

class AMainMenuGameMode;

/**
 * 
 */
UCLASS()
class OBSTACLEASSULT_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	void OpenLevel();

	UFUNCTION(BlueprintCallable)
	void StartGame();

	UFUNCTION(BlueprintCallable)
	void QuitGame();

	UFUNCTION(BlueprintCallable)
	void BackButton();

protected:

	virtual void NativeConstruct() override;

	UPROPERTY()
	class UMainMenuWidget* MainWidget;

	UPROPERTY()
	class UMainMenuWidget* LevelSelectionWidget;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	FString LevelName;

	UPROPERTY()
	AMainMenuGameMode* MainMenuGameMode;

};

