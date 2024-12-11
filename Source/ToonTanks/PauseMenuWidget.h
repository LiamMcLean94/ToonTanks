// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "PauseMenuWidget.generated.h"


/**
 * 
 */
UCLASS()
class TOONTANKS_API UPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

private:
    // Buttons bound from the Blueprint widget (WBP_PauseMenu)
    UPROPERTY(meta = (BindWidget))
    UButton* ResumeButton;

    UPROPERTY(meta = (BindWidget))
    UButton* MainMenuButton;

    UPROPERTY(meta = (BindWidget))
    UButton* QuitButton;

    // Functions to handle the button clicks
    UFUNCTION()
    void OnResumeButtonClicked();

    UFUNCTION()
    void OnMainMenuButtonClicked();

    UFUNCTION()
    void OnQuitButtonClicked();
	
};
