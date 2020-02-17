// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	initialLocation = FVector(0.0f, 0.0f, 0.0f);
	placedLocation = FVector(0.0f, 0.0f, 0.0f);
	worldOrigin = FVector(0.0f, 0.0f, 0.0f);
	initialDirection = FVector(0.0f, 0.0f, 0.0f);
	initialForce = FVector(0.0f);
	initialTorque = FVector(0.0f);
	
	bInitializeFloaterLocations = false;
	bShouldFloat = false;

	runningTime = 0.f;
	amplitude = 1;
	timeStrech = 1;
	
	
	cppStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh")); // Initialize variable

}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	/*
	float initialX = FMath::FRandRange(-300.0f, 500.0f);
	float initialY = FMath::FRandRange(-300.0f, 500.0f);
	float initialZ = FMath::FRandRange(-300.0f, 500.0f);
	
	initialLocation.X = initialX;
	initialLocation.Y = initialY;
	initialLocation.Z = initialZ;

	*/

	/**
	cppStaticMesh->AddForce(initialForce);
	cppStaticMesh->AddTorque(initialTorque);
	*/
	placedLocation = GetActorLocation();

	if (bInitializeFloaterLocations)
	{
		SetActorLocation(initialLocation);
	}
	/*
	FRotator localRotate = FRotator(25.f, 0.0f, 0.0f);
	AddActorLocalRotation(localRotate);

	FHitResult hitResult;
	FVector localOffset = FVector(200.f, 0.0f, 0.0f);
	AddActorLocalOffset(localOffset, true, &hitResult);
*/
}

// Called every frame
void AFloater::Tick(float DeltaTime)

{
	Super::Tick(DeltaTime);

	if (bShouldFloat)
	{
		FVector newLocation = GetActorLocation();

		newLocation.X = newLocation.X + amplitude * FMath::Sin(timeStrech * runningTime);
		newLocation.Y = newLocation.Y + amplitude *FMath::Cos(timeStrech * runningTime);
				
		SetActorLocation(newLocation);
		runningTime += DeltaTime;

	}




	/*
	if (bShouldFloat)
	{
		FHitResult hitResult;
		AddActorLocalOffset(initialDirection, true, &hitResult);

		FVector hitLocation = hitResult.Location;

		
		if (hitResult.bBlockingHit)
		{

			UE_LOG(LogTemp, Warning, TEXT(" Hit location is: X = %f, Y = %f, Z = %f"), hitLocation.X, hitLocation.Y, hitLocation.Z);
		}

		
	}*/
}



