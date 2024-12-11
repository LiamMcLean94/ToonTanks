// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ADoor::ADoor()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	
	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	RootComponent = DoorMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (CubeMeshAsset.Succeeded())
	{
		DoorMesh->SetStaticMesh(CubeMeshAsset.Object);
	}

	DoorMesh->SetRelativeScale3D(FVector(5.f, 1.f, 5.f)); 

	MoveSpeed = 5.0f; 
	MoveDistance = 500.0f;

	//InitialPosition = GetActorLocation();
	//MovedPosition = InitialPosition + FVector(0, -MoveDistance, 0);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	InitialPosition = GetActorLocation();
	MovedPosition = InitialPosition + FVector(0, -MoveDistance, 0);
	//OpenedPosition = InitialPosition + FVector(0, 0, OpenDistance); // Modify direction as needed
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}
void ADoor::MoveDoorLeft()
{
	SetActorLocation(MovedPosition); 
	UE_LOG(LogTemp, Warning, TEXT("Door Moved to Left at Location: %s"), *MovedPosition.ToString());
}


void ADoor::ResetDoorPosition()
{
	SetActorLocation(InitialPosition);  
	UE_LOG(LogTemp, Warning, TEXT("Door Reset to Initial Position: %s"), *InitialPosition.ToString());
}

