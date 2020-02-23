// Fill out your copyright notice in the Description page of Project Settings.


#include "NinjaCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ANinjaCharacter::ANinjaCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create SpringArm
	mainCameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("MainCameraBoom"));
	mainCameraBoom->TargetArmLength = 600.f;
	mainCameraBoom->bUsePawnControlRotation = true;	// Rotate arm based on controller

	// Create Camera
	mainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	mainCamera->SetupAttachment(mainCameraBoom, USpringArmComponent::SocketName);
	mainCamera->bUsePawnControlRotation = false;	


	



}

// Called when the game starts or when spawned
void ANinjaCharacter::BeginPlay()
{
	Super::BeginPlay();


	
}

// Called every frame
void ANinjaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANinjaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

