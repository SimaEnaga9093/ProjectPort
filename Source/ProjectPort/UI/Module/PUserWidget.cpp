// Fill out your copyright notice in the Description page of Project Settings.


#include "PUserWidget.h"

#include "Kismet/GameplayStatics.h"
#include "../../ProjectPortGameModeBase.h"

UPUserWidget::UPUserWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

AProjectPortGameModeBase* UPUserWidget::GetPortGameMode()
{
    return Cast<AProjectPortGameModeBase>(UGameplayStatics::GetGameMode(this));
}
