// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovingPlatform(DeltaTime);
	RotatingPlatform(DeltaTime);
}

void AMovingPlatform::MovingPlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
	SetActorLocation(CurrentLocation);
	DistanceMoved = GetDistanceMoved();

	if (DistanceMoved >= MoveDistance)
	{

		float OverShoot = DistanceMoved - MoveDistance;
		UE_LOG(LogTemp, Warning, TEXT("Overshoot: %f"), OverShoot);
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		FVector NewStartLocation = StartLocation + MoveDirection * MoveDistance;
		StartLocation = NewStartLocation;
		PlatformVelocity = -PlatformVelocity;
		DistanceMoved = 0.0f;
	}
}

void AMovingPlatform::RotatingPlatform(float DeltaTime)
{
	// This function is currently empty and can be implemented to handle platform rotation if needed.
	FRotator RotationToAdd = RotationVelocity * DeltaTime;
	AddActorLocalRotation(RotationToAdd);
}

float AMovingPlatform::GetDistanceMoved()
{
	
	return FVector::Dist(StartLocation, GetActorLocation());
}



