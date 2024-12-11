// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PressurePlate.generated.h"

UCLASS()
class TOONTANKS_API APressurePlate : public AActor
{
	GENERATED_BODY()
	
public:	
	
	APressurePlate();


public:	
	
	virtual void Tick(float DeltaTime) override;
    
    UPROPERTY(VisibleAnywhere)
    class UBoxComponent* PressurePlate;

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pressure Plate")
    class ADoor* Door;

    
    UFUNCTION()
    void OnPressurePlateOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnPressurePlateOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
        UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);
};
