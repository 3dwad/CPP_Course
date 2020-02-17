// Fill out your copyright notice in the Description page of Project Settings.


#include "Critter.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"


// Sets default values
ACritter::ACritter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	MainMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	
	MainMesh->SetupAttachment(GetRootComponent());
	MainCamera->SetupAttachment(GetRootComponent());

	MainCamera->SetRelativeLocation(FVector(-300.f, 0.f, 0.f));
	MainCamera->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));

	currentVelocity = FVector(0.f);
	maxSpeeed = 100.f;

}

// Called when the game starts or when spawned
void ACritter::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ACritter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	FVector newLocation = GetActorLocation() + (currentVelocity * DeltaTime);
	SetActorLocation(newLocation, true);
	

}

// Called to bind functionality to input
void ACritter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// BindAxis 
	
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACritter::MoveForwaard);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACritter::MoveRight);


}


void ACritter::MoveForwaard(float Value)
{

	currentVelocity.X = FMath::Clamp(Value, -1.f,1.f) * maxSpeeed;

}

void ACritter::MoveRight(float Value)
{

	currentVelocity.Y = FMath::Clamp(Value, -1.f, 1.f) * maxSpeeed;

}