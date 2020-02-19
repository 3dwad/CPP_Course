// Fill out your copyright notice in the Description page of Project Settings.


#include "ColliderMovementComponent.h"



void UColliderMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction); // Call parent Function

	// Check to make sure everything is still valid and that we are allowed to move

	if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
	{

		return;
	}
	
	// Get and clear the vector from Collider
	FVector desiredMoveThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 150.f;

	if (!desiredMoveThisFrame.IsNearlyZero())
	{
		FHitResult Hit;
		SafeMoveUpdatedComponent(desiredMoveThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

		// If we bump into something, slide along the side of it
		if (Hit.IsValidBlockingHit())
		{
			SlideAlongSurface(desiredMoveThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);

		}
	}
}