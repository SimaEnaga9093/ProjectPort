// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectPortGameModeBase.h"

void AProjectPortGameModeBase::StartPlay()
{
	Super::StartPlay();

	if (MainHUDWidgetClass)
	{
		MainHUDWidget = CreateWidget<UPUserWidget>(GetWorld(), MainHUDWidgetClass);
		MainHUDWidget->AddToViewport(0);
	}
}
