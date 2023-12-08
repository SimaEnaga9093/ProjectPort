// Fill out your copyright notice in the Description page of Project Settings.


#include "PMainHUDWidget.h"

#include "../Module/PCommonButton.h"
#include "Components/Button.h"
#include "../../ProjectPortGameModeBase.h"

UPMainHUDWidget::UPMainHUDWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	HUDNameText = FText::FromString("");
}

void UPMainHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CommonButtonQuest)
	{
		CommonButtonQuest->GetButtonBG()->OnClicked.AddDynamic(this, &UPMainHUDWidget::OnButtonQuestClicked);
	}
}

void UPMainHUDWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (CommonButtonQuest)
	{
		CommonButtonQuest->GetButtonBG()->OnClicked.RemoveDynamic(this, &UPMainHUDWidget::OnButtonQuestClicked);
	}
}

void UPMainHUDWidget::OnButtonQuestClicked()
{
	GetPortGameMode()->OpenHUDWidget(TEXT("WBP_QuestHUD"), 0);
}
