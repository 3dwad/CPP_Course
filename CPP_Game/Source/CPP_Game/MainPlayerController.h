// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CPP_GAME_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	

	// Reference to Asset
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<class UUserWidget> overlayAsset;
	//	Variable to hold Widget after creating it
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	class UUserWidget* HUDOverlay;

protected:

	virtual void BeginPlay() override;
};
