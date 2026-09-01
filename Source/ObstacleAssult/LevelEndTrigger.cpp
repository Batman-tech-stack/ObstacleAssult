// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelEndTrigger.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "ObstacleAssultGameMode.h"

// Sets default values
ALevelEndTrigger::ALevelEndTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	RootComponent = TriggerBox;

	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ALevelEndTrigger::OnplayerReachedEnd);


}

void ALevelEndTrigger::OnplayerReachedEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor || !OtherActor->IsA<ACharacter>())
	{
		return;
	}

	AObstacleAssultGameMode* GamMode = Cast<AObstacleAssultGameMode>(GetWorld()->GetAuthGameMode());

	if (GamMode)
	{
		GamMode->LevelCompleted();
	}
}

// Called when the game starts or when spawned
void ALevelEndTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALevelEndTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

