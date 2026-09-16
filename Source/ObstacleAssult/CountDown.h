// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CountDown.generated.h"

UCLASS()
class OBSTACLEASSULT_API UCountDown : public UUserWidget
{
    GENERATED_BODY()

protected:

    virtual void NativeConstruct() override;

    virtual void NativeTick(
        const FGeometry& MyGeometry,
        float InDeltaTime
    ) override;

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 CountDownTime = 3;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
    class USoundBase* BeepSound;

private:

    float CurrentCountDownTime = 0.0f;

    bool bCountdownFinished = false;

    UPROPERTY()
    APlayerController* PlayerController;

    void StartCountDown(float DeltaTime);
};