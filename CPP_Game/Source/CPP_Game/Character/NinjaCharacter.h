// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"
#include "NinjaCharacter.generated.h"

UCLASS()
class CPP_GAME_API ANinjaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANinjaCharacter();

	// Main spring arm
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPricateAcces = "true")) // AllowPrivateAcces its mean we can work with that property from this blueprint, even if him definition in private section
	class USpringArmComponent* mainCameraBoom;

	// Main camera
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPricateAcces = "true"))
	class UCameraComponent* mainCamera;

	// Base turn rate to scale turning functions for the camera
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly, Category = Camera)
	float baseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float baseLookUpRate;

	




protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	// Called for forward/backward input
	void CharacterMoveForward(float axisValue);

	// Called for right/left input
	void CharacterMoveRight(float axisValue);

	/** Called via input to turn at a given rate
	* @param rate this is normalized rate, i.e 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float rate);

		/** Called via input to look up/down at a given rate
		* @param rate this is normalized rate, i.e 1.0 means 100% of desired look up/down rate
		*/
	void LookUpRate(float rate);

	// Getters for Camera and SpringArm
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return mainCameraBoom; }
	FORCEINLINE class UCameraComponent* GetMainCamera() const { return mainCamera; }

};
