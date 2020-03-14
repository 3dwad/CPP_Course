// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform.generated.h"

UCLASS()
class CPP_GAME_API AFloatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingPlatform();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Platform)
	class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, Category = Platform)
	FVector startPoint;

	UPROPERTY(EditAnywhere, Category = Platform, meta = (MakeEditWidget = "true"))
	FVector endPoint;

	UPROPERTY(EditAnywhere, Category = Platform)
	float interpSpeed;

	UPROPERTY(EditAnywhere, Category = Platform)
	float interpTime;

	UPROPERTY(EditAnywhere, Category = Platform)
	float distanceToTargetPoint;

	FTimerHandle FinterpTimer;

	UPROPERTY(EditAnywhere, Category = Platform)
	bool bInterping;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(Category = Platform)
	void MovePlatform(float tick);

	UFUNCTION(Category = Platform)
	void ToggleInterping();

	UFUNCTION(Category = Platform)
	void SwapingVectors(FVector& vecOne, FVector& vecTwo);

};
