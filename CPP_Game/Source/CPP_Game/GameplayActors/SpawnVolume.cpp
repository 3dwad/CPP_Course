// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "CPP_Game\Pawn\Critter.h"


// Sets default values
ASpawnVolume::ASpawnVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));



}

// Called when the game starts or when spawned
void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetSpawnPoint()
{
	// Set vector ScaledExtend from SpawningBox into L_extend
	FVector L_extend = SpawningBox->GetScaledBoxExtent();

	// Set ComponentLocation from SpawningBox into L_origin
	FVector L_origin = SpawningBox->GetComponentLocation();

	// Call function from UKismetMathLibrary and set return into L_point
	FVector L_point = UKismetMathLibrary::RandomPointInBoundingBox(L_origin, L_extend);

	return L_point;

}

void ASpawnVolume::SpawnOurPawn_Implementation(UClass* classForSpawn, const FVector& location)
{

	if (classForSpawn)
	{

		UWorld* world = GetWorld();
		FActorSpawnParameters L_spawnParametrs;

		if (world)
		{

			// Call Spawn actor of class, and set L_critterSpawned
			ACritter* L_critterSpawned = world->SpawnActor<ACritter>(classForSpawn, location, FRotator(0.f), L_spawnParametrs);

		}

	}

}

