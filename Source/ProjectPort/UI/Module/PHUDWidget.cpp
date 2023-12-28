// Fill out your copyright notice in the Description page of Project Settings.


#include "PHUDWidget.h"

#include "../../ProjectPortGameModeBase.h"
#include "../PTopBarWidget.h"

void UPHUDWidget::OnOpen()
{
	//UE_LOG(LogTemp, Log, TEXT("UPHUDWidget::OnOpen %s"), *GetName());

	GetPortGameMode()->GetTopBarWidget()->SetNameText(HUDNameText);
}

void UPHUDWidget::OnClose()
{
	//UE_LOG(LogTemp, Log, TEXT("UPHUDWidget::OnClose %s"), *GetName());
}

void UPHUDWidget::OnBack()
{
	//UE_LOG(LogTemp, Log, TEXT("UPHUDWidget::OnBack %s"), *GetName());
}

bool UPHUDWidget::HandleBackAction()
{
	//UE_LOG(LogTemp, Log, TEXT("UPHUDWidget::HandleBackAction %s"), *GetName());
	return false;
}
