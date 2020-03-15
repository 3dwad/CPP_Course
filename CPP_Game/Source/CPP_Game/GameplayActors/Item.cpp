// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Sound/SoundCue.h"
#include "DrawDebugHelpers.h"
#include "CPP_Game/CPP_Game.h"



// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	CollisionVolume = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionVolume"));
	RootComponent = CollisionVolume;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(GetRootComponent());
	
	IdleParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("IdleParticle"));
	IdleParticle->SetupAttachment(GetRootComponent());
	
	bRotate = false;
	rotationRate = 0.25f;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	// Absolutely must full qualified function name
	CollisionVolume->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnItemOverlapBegin);
	CollisionVolume->OnComponentEndOverlap.AddDynamic(this, &AItem::OnItemOverlapEnd);

	
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Rotator(DeltaTime);

}

void AItem::OnItemOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Super::OverlapBegin"));

	//	 Debug string right into world
	DrawDebugString(GetWorld(),GetActorLocation(),"Overlap!",nullptr,FColor::Red,2.f);

	if (OnOverlapParticle)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(),OnOverlapParticle, GetActorTransform(), true);
		Destroy();
	}

	if (Sound)
	{
		UGameplayStatics::PlaySound2D(this, Sound);
	}

}

void AItem::OnItemOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Super::OverlapEnd"));


}

void AItem::Rotator(float DeltaTime)
{
	if (bRotate)
	{
		FRotator L_Rotate = GetActorRotation();

		L_Rotate.Yaw += (rotationRate*DeltaTime);
		SetActorRotation(L_Rotate);

		// Debug via AddOnScreenMessage
		/*FString L_DebugMSG = L_Rotate.ToString();
		GEngine->AddOnScreenDebugMessage(1, 0.f, FColor::Green, L_DebugMSG);

		//	Debug via UE_Log, also use custom MyLog category
		// UE_LOG(MyLog, Warning, TEXT("L_Rotate = %s"), *L_DebugMSG);
		*/
		
	}


}

