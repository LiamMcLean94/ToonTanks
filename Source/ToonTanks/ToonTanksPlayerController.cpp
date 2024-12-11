// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksPlayerController.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "GameHUD.h"


void AToonTanksPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
	if (bPlayerEnabled) 
	{
		GetPawn()->EnableInput(this);
	}

	else
	{
		GetPawn()->DisableInput(this);
	}
	bShowMouseCursor = bPlayerEnabled;
}

//Binding for menu
void AToonTanksPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();
    InputComponent->BindAction("Pause", IE_Pressed, this, &AToonTanksPlayerController::TogglePauseMenu);
}

void AToonTanksPlayerController::TogglePauseMenu()
{
    AGameHUD* HUD = Cast<AGameHUD>(GetHUD());
    if (HUD)
    {
        if (UGameplayStatics::IsGamePaused(GetWorld()))
        {
            HUD->HidePauseMenu();
        }
        else
        {
            HUD->ShowPauseMenu();
        }
    }
}

