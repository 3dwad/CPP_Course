// Fill out your copyright notice in the Description page of Project Settings.


#include "TestObject.h"

UTestObject::UTestObject()
{

	myCPPFloat = 20.0f;

}

void UTestObject::MyCPPFunction()
{

	UE_LOG(LogTemp, Warning, TEXT("This is our warning text"));

}