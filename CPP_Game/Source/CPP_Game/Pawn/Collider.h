// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Collider.generated.h"

UCLASS()
class CPP_GAME_API ACollider : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollider();
	   
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Declaration Static Mesh component
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* meshComponent;

	// Declaration Sphere collision component component
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class USphereComponent* sphereComponent;

	// Declaration Floating Pawn Movement Component
	UPROPERTY(VisibleAnywhere, Category = "Movement")
	class UFloatingPawnMovement* floatingMovementComponent;

	// Declaration Camera component
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class UCameraComponent* mainCamera;

	// Declaration Camera component
	UPROPERTY(VisibleAnywhere, Category = "Camera")
	class USpringArmComponent* mainSpringArm;


	// Getters and Setters
	
	FORCEINLINE UStaticMeshComponent* GetMeshComponent() {return meshComponent;}
	FORCEINLINE void SetMeshComponent(UStaticMeshComponent* Mesh) {meshComponent = Mesh;}
	FORCEINLINE USphereComponent* GetSphereComponent() { return sphereComponent; }
	FORCEINLINE void SetSphereComponent(USphereComponent* Sphere) { sphereComponent = Sphere; }


	FORCEINLINE UCameraComponent* GetCameraComponent() { return mainCamera; }
	FORCEINLINE void SetCameraComponent(UCameraComponent* camera) { mainCamera = camera; }
	FORCEINLINE USpringArmComponent* GetSpringArmComponent() { return mainSpringArm; }
	FORCEINLINE void SetSpringArmComponent(USpringArmComponent* springArm) { mainSpringArm = springArm; }

private:
	void MoveForward(float axisValue);
	void MoveRight(float axisValue);

	
};
