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

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class UStaticMeshComponent* meshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	class USphereComponent* sphereComponent;


	// Getters ans Setters
	UFUNCTION(BlueprintCallable, Category = "Getters")
	FORCEINLINE UStaticMeshComponent* GetMeshComponent() {return meshComponent;}

	UFUNCTION(BlueprintCallable, Category = "Setters")
	FORCEINLINE void SetMeshComponent(UStaticMeshComponent* Mesh) {meshComponent = Mesh;}


	UFUNCTION(BlueprintCallable, Category = "Getters")
	FORCEINLINE USphereComponent* GetSphereComponent() { return sphereComponent; }

	UFUNCTION(BlueprintCallable, Category = "Setters")
	FORCEINLINE void SetSphereComponent(USphereComponent* Sphere) { sphereComponent = Sphere; }
};
