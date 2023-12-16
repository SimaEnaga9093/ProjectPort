// Fill out your copyright notice in the Description page of Project Settings.


#include "PToastMessageWidget.h"

#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "../../ProjectPortGameModeBase.h"

void UPToastMessageWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	TextMessage->SetText(MessageText);
}

void UPToastMessageWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ButtonBG)
		ButtonBG->OnClicked.AddDynamic(this, &UPToastMessageWidget::OnButtonBGClicked);
}

void UPToastMessageWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (ButtonBG)
		ButtonBG->OnClicked.RemoveDynamic(this, &UPToastMessageWidget::OnButtonBGClicked);
}

void UPToastMessageWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if (!IsMessageShowned)
		return;

	LifeTimer += InDeltaTime;
	if (LifeTimer >= LifeTime)
		GetPortGameMode()->CloaseToastMessageWidget();
}

void UPToastMessageWidget::OnButtonBGClicked()
{
	GetPortGameMode()->CloaseToastMessageWidget();
}

void UPToastMessageWidget::OpenToastMessage()
{
	TextMessage->SetText(MessageText);
	LifeTime = 3.0f;
	IsMessageShowned = true;
}

void UPToastMessageWidget::CloaseToastMessage()
{
	LifeTimer = 0.0f;
	IsMessageShowned = false;
}

