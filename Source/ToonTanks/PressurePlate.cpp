// Fill out your copyright notice in the Description page of Project Settings.


#include "PressurePlate.h"
#include "Components/BoxComponent.h"
#include "Door.h"
#include "GameFramework/Pawn.h"

// Sets default values
APressurePlate::APressurePlate()
{
 	
	PrimaryActorTick.bCanEverTick = true;

    
    PressurePlate = CreateDefaultSubobject<UBoxComponent>(TEXT("PressurePlate"));
    RootComponent = PressurePlate;

    
    PressurePlate->OnComponentBeginOverlap.AddDynamic(this, &APressurePlate::OnPressurePlateOverlapBegin);
    PressurePlate->OnComponentEndOverlap.AddDynamic(this, &APressurePlate::OnPressurePlateOverlapEnd);
}



// Called every frame
void APressurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APressurePlate::OnPressurePlateOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    // Check if the overlapped actor is a Pawn (or player)
    if (OtherActor && OtherActor != this && OtherActor->IsA(APawn::StaticClass()))
    {
        if (Door)
        {
            // Debug log for triggering the door
            UE_LOG(LogTemp, Warning, TEXT("Pressure Plate Triggered: Opening Door"));
            Door->MoveDoorLeft();
        }
    }
}

void APressurePlate::OnPressurePlateOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
    // Check if the overlapped actor is a Pawn (or player)
    if (OtherActor && OtherActor != this && OtherActor->IsA(APawn::StaticClass()))
    {
        if (Door)
        {
            // Debug log for closing the door when the player leaves
            UE_LOG(LogTemp, Warning, TEXT("Pressure Plate Ended: Closing Door"));
            Door->ResetDoorPosition();
        }
    }
}

