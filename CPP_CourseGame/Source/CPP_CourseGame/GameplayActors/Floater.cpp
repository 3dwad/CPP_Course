// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"

// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	initialLocation = FVector(0.0f, 0.0f, 0.0f);
	placedLocation = FVector(0.0f, 0.0f, 0.0f);
	worldOrigin = FVector(0.0f, 0.0f, 0.0f);
	initialDirection = FVector(0.0f, 0.0f, 0.0f);

	bInitializeFloaterLocations = false;
	bShouldFloat = false;

	
	cppStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh")); // Initialize variable

}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();
	
	placedLocation = GetActorLocation();

	if (bInitializeFloaterLocations)
	{
		SetActorLocation(initialLocation);
	}
	
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bShouldFloat)
	{
		FHitResult hitResult;
		AddActorLocalOffset(initialDirection, true, &hitResult);

		FVector hitLocation = hitResult.Location;

		if (hitResult.bBlockingHit)
		{

			UE_LOG(LogTemp, Warning, TEXT(" Hit location is: X = %f, Y = %f, Z = %f"), hitLocation.X, hitLocation.Y, hitLocation.Z);
		}

		
	}
}



