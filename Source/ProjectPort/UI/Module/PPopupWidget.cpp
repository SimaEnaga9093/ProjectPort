// Fill out your copyright notice in the Description page of Project Settings.


#include "PPopupWidget.h"

#include "../../ProjectPortGameModeBase.h"

void UPPopupWidget::OnOpen()
{
	UE_LOG(LogTemp, Log, TEXT("UPPopupWidget::OnOpen %s"), *GetName());
}

void UPPopupWidget::OnClose()
{
	UE_LOG(LogTemp, Log, TEXT("UPPopupWidget::OnClose %s"), *GetName());
}

bool UPPopupWidget::HandleCloseAction()
{
	UE_LOG(LogTemp, Log, TEXT("UPPopupWidget::HandleCloseAction %s"), *GetName());
	return false;
}

void UPPopupWidget::ClosePopup()
{
	GetPortGameMode()->ClosePopup(this);
}
