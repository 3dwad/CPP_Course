// Fill out your copyright notice in the Description page of Project Settings.


#include "NinjaAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

void UNinjaAnimInstance::NativeInitializeAnimation()
{
	// Take anim instance owner and set him into pawn variable
	if (pawn == nullptr)
	{
		pawn = TryGetPawnOwner();
	}
	}


// Function for every tick update movement speed and in air state
void UNinjaAnimInstance::UpdateAnimationProperties()
{
	// Just to be sure
	if (pawn == nullptr)
	{
		pawn = TryGetPawnOwner();

	}

	if (pawn)
	{

		FVector L_speed = pawn->GetVelocity();	// Get Velocity of pawn
		FVector L_lateralSpeed = FVector(L_speed.X, L_speed.Y, 0.f);	// Create local FVector to get only X and Y values from pawn speed
		movementSpeed = L_lateralSpeed.Size();	// Get vector length and set this value to movementSpeed

		bIsInAir = pawn->GetMovementComponent()->IsFalling();	// Get standard bool value from movement component
	}

}


