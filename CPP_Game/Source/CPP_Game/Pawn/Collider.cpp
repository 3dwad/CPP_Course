// Fill out your copyright notice in the Description page of Project Settings.


#include "Collider.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
// #include "UObject/ConstructorHelpers.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/InputComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ACollider::ACollider()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));

	sphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	sphereComponent->SetupAttachment(GetRootComponent());

	sphereComponent->InitSphereRadius(40.f);
	sphereComponent->SetCollisionProfileName(TEXT("Pawn"));

	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	meshComponent->SetupAttachment(GetRootComponent());

	floatingMovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Movement"));

	mainSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	mainSpringArm->SetupAttachment(GetRootComponent());
	mainSpringArm->SetRelativeRotation(FRotator(-45.f, 0.f, 0.f));
	mainSpringArm->TargetArmLength = 400.f;
	mainSpringArm->bEnableCameraLag = true;
	mainSpringArm->CameraLagSpeed = 3.0f;

	
	mainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	mainCamera->SetupAttachment(mainSpringArm, USpringArmComponent::SocketName);
	
	



	/* Hard coding to push StaticMesh.

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshComponentAsset(TEXT("StaticMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Gruntling_Weapons/Meshes/SM_Gruntling_BombDrop_Internal.SM_Gruntling_BombDrop_Internal'"));
	 if (MeshComponentAsset.Succeeded())
	 {
		 meshComponent->SetStaticMesh(MeshComponentAsset.Object);
		 meshComponent->SetRelativeLocation(FVector(0.f,0.f,-5.f));
		 meshComponent->SetWorldScale3D(FVector(1.2f));
	 }
	 */

}

// Called when the game starts or when spawned
void ACollider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACollider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACollider::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// BindAxis 

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ACollider::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ACollider::MoveRight);

}

// Get Actor vectors, multiply to value from input and add movement input

void ACollider::MoveForward(float axisValue)
{
	FVector forwardActorVector = GetActorForwardVector();

	AddMovementInput(axisValue * forwardActorVector);

}

void ACollider::MoveRight(float axisValue)
{
	FVector rightActorVector = GetActorRightVector();

	AddMovementInput(axisValue * rightActorVector);
}


