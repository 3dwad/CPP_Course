// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPP_Game/GameplayActors/Item.h"
#include "Explosive.generated.h"

/**
 * 
 */
UCLASS()
class CPP_GAME_API AExplosive : public AItem
{
	GENERATED_BODY()
	
public:

	AExplosive();
	
	
	virtual void OnItemOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	virtual void OnItemOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	
};
