// Fill out your copyright notice in the Description page of Project Settings.


#include "PUserWidget.h"

#include "PHUDWidget.h"

UPUserWidget::UPUserWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UPHUDWidget* UPUserWidget::OpenHUDWidget(const FString& HUDName, int ZOrder)
{
    const FString& Path = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/" + HUDName + "." + HUDName + "_C'");

    FSoftClassPath HUDClassRef(Path);
    if (UClass* NewHUDClass = HUDClassRef.TryLoadClass<UPHUDWidget>())
    {
        UPHUDWidget* NewHUDWidget = CreateWidget<UPHUDWidget>(GetWorld(), NewHUDClass);
        NewHUDWidget->AddToViewport(ZOrder);

        return NewHUDWidget;
    }

    return nullptr;
}
