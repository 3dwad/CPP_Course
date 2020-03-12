// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorSwitch.generated.h"

UCLASS()
class CPP_GAME_API AFloorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorSwitch();

	// Trigger volume for the function 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = FloorSwitch)
	class UBoxComponent* TriggerBox;

	// Switch for the character to step
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = FloorSwitch)
	class UStaticMeshComponent* FloorSwitch;

	// Door to move when the floor switch was pressed
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = FloorSwitch)
	UStaticMeshComponent* Door;


	// Initial location for the door
	UPROPERTY(BlueprintReadWrite,Category = FloorSwitch)
	FVector initialDoorLocation;

	// Initial location for door switch
	UPROPERTY(BlueprintReadWrite, Category = FloorSwitch)
	FVector initialSwitchLocation;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintImplementableEvent, Category = FloorSwitch)	// BlueprintImplementableEvent that mean we can define this function into blueprints
	void RaiseDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = FloorSwitch)	
	void LowerDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = FloorSwitch)	
	void RaiseFloorSwitch();

	UFUNCTION(BlueprintImplementableEvent, Category = FloorSwitch)	
	void LowerFloorSwitch();

	UFUNCTION(BlueprintCallable, Category = FloorSwitch)
	void UpdateDoorLocation(float Z);


};


