// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingPlatform.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AFloatingPlatform::AFloatingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	Mesh->SetupAttachment(GetRootComponent());

	startPoint = FVector(0.f);
	endPoint = FVector(0.f);
	interpSpeed = 0.f;
	bInterping = false;
	interpTime = 2.f;
}

// Called when the game starts or when spawned
void AFloatingPlatform::BeginPlay()
{
	Super::BeginPlay();

	startPoint = GetActorLocation();
	endPoint += GetActorLocation();

	
	GetWorldTimerManager().SetTimer(FinterpTimer, this, &AFloatingPlatform::ToggleInterping, interpTime);
	
}

// Called every frame
void AFloatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bInterping)
	{
		MovePlatform(DeltaTime);

		if (distanceToTargetPoint<=30.f)
		{
			ToggleInterping();
			SwapingVectors(startPoint, endPoint);
			GetWorldTimerManager().SetTimer(FinterpTimer, this, &AFloatingPlatform::ToggleInterping, interpTime);
		}
	}
		
}


void AFloatingPlatform::MovePlatform(float DeltaTime)
{

	FVector currentLocation = GetActorLocation();

	FVector vInterp = FMath::VInterpTo(currentLocation, endPoint, DeltaTime, interpSpeed);

	SetActorLocation(vInterp);

	distanceToTargetPoint = UKismetMathLibrary::Vector_Distance(GetActorLocation(), endPoint);

}

void AFloatingPlatform::ToggleInterping()
{
	// This function just flipping bool
	bInterping = !bInterping;

}

void AFloatingPlatform::SwapingVectors(FVector& vecOne, FVector& vecTwo)
{
	FVector temp = vecOne;
	vecOne = vecTwo;
	vecTwo = temp;


}
