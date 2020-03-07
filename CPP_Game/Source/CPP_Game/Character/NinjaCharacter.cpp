// Fill out your copyright notice in the Description page of Project Settings.

#include "NinjaCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/World.h"
#include "Components/InputComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ANinjaCharacter::ANinjaCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	// Create SpringArm
	mainCameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("MainCameraBoom"));
	mainCameraBoom->TargetArmLength = 600.f;
	mainCameraBoom->bUsePawnControlRotation = true;	// Rotate arm based on controller
	mainCameraBoom->SetupAttachment(GetRootComponent());	// Attach camera boom to root component

	// Create Camera
	mainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	mainCamera->SetupAttachment(mainCameraBoom, USpringArmComponent::SocketName);
	mainCamera->bUsePawnControlRotation = false;	

	// Set initialized size of capsule component. Also can use SetCapsuleSize function
	GetCapsuleComponent()->InitCapsuleSize(34.f, 88.f);	
	



	// Set our turn rates for input
	baseTurnRate = 65.f;
	baseLookUpRate = 65.f;

	// Disable rotation character follow controller
	// Only CameraBoom rotate follow controller
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	// Enable character rotation to movement direction
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 360.f, 0.f);	// Set value of Yaw rotation
	GetCharacterMovement()->JumpZVelocity = 650.f;	// Max Jump height
	GetCharacterMovement()->AirControl = 0.2f;	// In air control
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

	check(PlayerInputComponent);	// Check on valid. Stop all logic bellow if not valid

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ANinjaCharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ANinjaCharacter::StopJumping);


	// Inputs for Move
	PlayerInputComponent->BindAxis("MoveForward", this, &ANinjaCharacter::CharacterMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ANinjaCharacter::CharacterMoveRight);

	// Inputs for mouse rotation
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	// Inputs for keyboard rotation
	PlayerInputComponent->BindAxis("TurnRate", this, &ANinjaCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ANinjaCharacter::LookUpRate);

}

void ANinjaCharacter::CharacterMoveRight(float axisValue)
{
	if ((GetController() != nullptr) && (axisValue != 0.f))
	{

		// Find out which way is forward
		const FRotator controllerRotation = GetController()->GetControlRotation();
		const FRotator yawRotation(0.f, controllerRotation.Yaw, 0.f);

		// Get Y direction in local space
		const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(direction, axisValue);

	}
}


void ANinjaCharacter::CharacterMoveForward(float axisValue)
{
	if ((GetController() != nullptr) && (axisValue != 0.f))
	{

		// Find out which way is forward
		const FRotator controllerRotation = GetController()->GetControlRotation();
		const FRotator yawRotation(0.f, controllerRotation.Yaw, 0.f);

		// Get X direction in local space
		const FVector direction = FRotationMatrix(yawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(direction, axisValue);
	}
}


void ANinjaCharacter::TurnAtRate(float rate)
{

	AddControllerYawInput(rate * baseTurnRate * GetWorld()->GetDeltaSeconds());

}

void ANinjaCharacter::LookUpRate(float rate)
{
	AddControllerPitchInput(rate * baseLookUpRate * GetWorld()->GetDeltaSeconds());

}
