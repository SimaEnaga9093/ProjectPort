// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectPortGameModeBase.h"

#include "UI/Module/PHUDWidget.h"
#include "Kismet/GameplayStatics.h"

void AProjectPortGameModeBase::StartPlay()
{
	Super::StartPlay();

	if (MainHUDWidgetClass)
	{
		MainHUDWidget = CreateWidget<UPHUDWidget>(GetWorld(), MainHUDWidgetClass);
		MainHUDWidget->AddToViewport(0);
	}

    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    PC->SetShowMouseCursor(true);
    PC->SetInputMode(FInputModeGameAndUI());
    PC->InputComponent->BindAction("Back", IE_Pressed, this, &AProjectPortGameModeBase::OnBackPressed);
}

void AProjectPortGameModeBase::OnBackPressed()
{
    if (HUDWidgetHistory.IsEmpty())
        return;

    if (MainHUDWidget->HandleBackAction())
        return;
    MainHUDWidget->OnBack();
    MainHUDWidget->RemoveFromParent();

    TSoftObjectPtr<UPHUDWidget> LastHUDWidget = HUDWidgetHistory.Last();
    if (LastHUDWidget)
    {
        HUDWidgetHistory.Remove(LastHUDWidget);

        LastHUDWidget->AddToViewport();
        LastHUDWidget->OnOpen();
        MainHUDWidget = LastHUDWidget;
    }
}

UPHUDWidget* AProjectPortGameModeBase::OpenHUDWidget(const FString& HUDName, int ZOrder)
{
    const FString& Path = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/" + HUDName + "." + HUDName + "_C'");

    FSoftClassPath HUDClassRef(Path);
    if (UClass* NewHUDClass = HUDClassRef.TryLoadClass<UPHUDWidget>())
    {
        MainHUDWidget->OnClose();
        MainHUDWidget->RemoveFromParent();
        HUDWidgetHistory.Add(MainHUDWidget);

        UPHUDWidget* NewHUDWidget = CreateWidget<UPHUDWidget>(GetWorld(), NewHUDClass);
        NewHUDWidget->AddToViewport(ZOrder);
        NewHUDWidget->OnOpen();
        MainHUDWidget = NewHUDWidget;

        return NewHUDWidget;
    }

    return nullptr;
}
