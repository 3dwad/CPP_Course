// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TestObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CPP_COURSEGAME_API UTestObject : public UObject
{
	GENERATED_BODY()

public:
	UTestObject();
		
	UPROPERTY(BlueprintReadWrite, category = "My Category")
	float myCPPFloat;

	UFUNCTION(BlueprintCallable)
	void MyCPPFunction();

};
