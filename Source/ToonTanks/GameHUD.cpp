// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"
#include "Kismet/GameplayStatics.h"


void AGameHUD::BeginPlay()
{
	Super::BeginPlay();
	
	FString CurrentLevelName = GetWorld()->GetMapName();
	
	if (CurrentLevelName.EndsWith("MainMenuLevel"))
	{
		ShowMainMenu();
	}

}

void AGameHUD::ShowMainMenu()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ShowMainMenu Called"));
	}
	if (!MainMenuWidgetClass) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MainMenuWidgetClass is NOT set!"));
		return;
	}
	MainMenuWidget = CreateWidget<UUserWidget>(GetWorld(), MainMenuWidgetClass);
	
	if (!MainMenuWidget)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("MainMenuWidget creation failed!"));
		return;
	}
	if (MainMenuWidget)
	{
		MainMenuWidget->AddToViewport();

		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		if (PlayerController)
		{
			PlayerController->bShowMouseCursor = true;
			PlayerController->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AGameHUD::HideMainMenu()
{
	if (MainMenuWidget)
	{
		MainMenuWidget->RemoveFromParent();
		MainMenuWidget = nullptr;

		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		if (PlayerController)
		{
			PlayerController->bShowMouseCursor = true;
			
			PlayerController->SetInputMode(FInputModeGameOnly());
		}
	}
}

void AGameHUD::ShowPauseMenu()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("ShowPauseMenu Called"));
	}

	if (!PauseMenuWidgetClass) return;

	PauseMenuWidget = CreateWidget<UUserWidget>(GetWorld(), PauseMenuWidgetClass);
	if (PauseMenuWidget)
	{
		PauseMenuWidget->AddToViewport();
		UGameplayStatics::SetGamePaused(GetWorld(), true);

		// Show mouse cursor and set input to UI
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		if (PlayerController)
		{
			PlayerController->bShowMouseCursor = true;
			PlayerController->SetInputMode(FInputModeUIOnly());
		}
	}
}

void AGameHUD::HidePauseMenu()
{
	if (PauseMenuWidget)
	{
		PauseMenuWidget->RemoveFromParent();
		PauseMenuWidget = nullptr;
		UGameplayStatics::SetGamePaused(GetWorld(), false);

		// Hide mouse cursor and set input back to game
		APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
		if (PlayerController)
		{
			
			FInputModeGameOnly InputMode;
			InputMode.SetConsumeCaptureMouseDown(true); // Ensures that mouse clicks are captured and not wasted refocusing
			PlayerController->SetInputMode(InputMode);

			
		}
	}


}

