// Fill out your copyright notice in the Description page of Project Settings.


#include "FloorSwitch.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"

// Sets default values
AFloorSwitch::AFloorSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent->SetupAttachment(GetRootComponent());
	
	TriggerBox = CreateAbstractDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->SetupAttachment(RootComponent);
	
	// Below i set collision channel for trigger box, set response ignore all channels, and then turn on overlap events with pawn. Also set box extend.
	
	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);	
	TriggerBox->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	TriggerBox->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn,ECollisionResponse::ECR_Overlap);
	TriggerBox->SetBoxExtent(FVector(62.f, 62.f, 32.f));

	FloorSwitch = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorSwitch"));
	FloorSwitch->SetupAttachment(GetRootComponent());

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(GetRootComponent());

	switchTimerDelay = 2.f;
	bCharacterOnSwitch = false;
}

// Called when the game starts or when spawned
void AFloorSwitch::BeginPlay()
{
	Super::BeginPlay();
	
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &AFloorSwitch::OnOverlapBegin);	// .AddDynamic call delegate from TriggerBox. Then we set parameters from him into our custom OnOverlapBegin function
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &AFloorSwitch::OnOverlapEnd);	// Another bind function for component end overlap

	// Set initial locations
	initialDoorLocation = Door->GetComponentLocation();
	initialSwitchLocation = FloorSwitch->GetComponentLocation();

}

// Called every frame
void AFloorSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFloorSwitch::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

	UE_LOG(LogTemp, Warning, TEXT("Overlap Begin."));

	if (!bCharacterOnSwitch) bCharacterOnSwitch = true;
	RaiseDoor();
	LowerFloorSwitch();
	
}


void AFloorSwitch::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	UE_LOG(LogTemp, Warning, TEXT("Overlap End."));

	
	bCharacterOnSwitch = false;

	//	Equal SetTimerByFunction in blueprints
	GetWorldTimerManager().SetTimer(switchHandle, this, &AFloorSwitch::CloseDoor, switchTimerDelay);
		
}

void AFloorSwitch::UpdateDoorLocation(float Z)
{
	FVector L_newLocation = initialDoorLocation;
	L_newLocation.Z += Z;

	Door->SetWorldLocation(L_newLocation);

}

void AFloorSwitch::UpdateFloorSwitchLocation(float Z)
{
	FVector L_newLocation = initialSwitchLocation;
	L_newLocation.Z += Z;

	FloorSwitch->SetWorldLocation(L_newLocation);

}

void AFloorSwitch::CloseDoor()
{
	

	if (!bCharacterOnSwitch)
	{
		UE_LOG(LogTemp, Warning, TEXT("CloseDoor Called"));
		LowerDoor();
		RaiseFloorSwitch();

	}
	

}




