// Fill out your copyright notice in the Description page of Project Settings.


#include "PauseMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UPauseMenuWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (ResumeButton)
    {
        ResumeButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnResumeButtonClicked);
    }
    if (MainMenuButton)
    {
        MainMenuButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnMainMenuButtonClicked);
    }
    if (QuitButton)
    {
        QuitButton->OnClicked.AddDynamic(this, &UPauseMenuWidget::OnQuitButtonClicked);
    }
}

void UPauseMenuWidget::OnResumeButtonClicked()
{
    RemoveFromParent();

    UGameplayStatics::SetGamePaused(GetWorld(), false);
    
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    if (PC)
    {
        PC->bShowMouseCursor = true;
        PC->SetInputMode(FInputModeGameOnly());
    }
}

void UPauseMenuWidget::OnMainMenuButtonClicked()
{
    
    UGameplayStatics::OpenLevel(GetWorld(), FName("MainMenuLevel"));
}

void UPauseMenuWidget::OnQuitButtonClicked()
{
    APlayerController* PC = GetWorld()->GetFirstPlayerController();
    UKismetSystemLibrary::QuitGame(GetWorld(), PC, EQuitPreference::Quit, true);
}
