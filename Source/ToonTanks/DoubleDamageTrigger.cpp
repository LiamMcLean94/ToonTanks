// Fill out your copyright notice in the Description page of Project Settings.


#include "DoubleDamageTrigger.h"
#include "Components/BoxComponent.h"
#include "Tank.h"

// Sets default values
ADoubleDamageTrigger::ADoubleDamageTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;

	CollisionBox->SetCollisionProfileName("Trigger");
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ADoubleDamageTrigger::OnOverlapBegin);


}

// Called when the game starts or when spawned
void ADoubleDamageTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
/*void ADoubleDamageTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/

void ADoubleDamageTrigger::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (ATank* Tank = Cast<ATank>(OtherActor))
	{
		UE_LOG(LogTemp, Warning, TEXT("Double Damage Activated for Tank: %s"), *Tank->GetName());
		Tank->ActivateDoubleDamage();
		UE_LOG(LogTemp, Warning, TEXT("Tank double damage active state: %s"), Tank->IsDoubleDamageActive() ? TEXT("true") : TEXT("false"));
	}
}

