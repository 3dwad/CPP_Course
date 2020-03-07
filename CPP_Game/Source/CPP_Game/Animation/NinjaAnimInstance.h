// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "NinjaAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class CPP_GAME_API UNinjaAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	// Declaration of virtual function
	virtual void NativeInitializeAnimation() override;

	UFUNCTION(BlueprintCallable, Category = AnimationProperties)
	void UpdateAnimationProperties();


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	float movementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	bool bIsInAir;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	class APawn* pawn;





};
