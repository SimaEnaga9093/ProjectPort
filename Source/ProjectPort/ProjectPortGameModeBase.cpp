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
    PC->SetInputMode(FInputModeUIOnly());
}

UPHUDWidget* AProjectPortGameModeBase::OpenHUDWidget(const FString& HUDName, int ZOrder)
{
    const FString& Path = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/" + HUDName + "." + HUDName + "_C'");

    FSoftClassPath HUDClassRef(Path);
    if (UClass* NewHUDClass = HUDClassRef.TryLoadClass<UPHUDWidget>())
    {
        UPHUDWidget* NewHUDWidget = CreateWidget<UPHUDWidget>(GetWorld(), NewHUDClass);
        NewHUDWidget->AddToViewport(ZOrder);

        MainHUDWidget->RemoveFromParent();
        MainHUDWidget = NewHUDWidget;

        return NewHUDWidget;
    }

    return nullptr;
}
