// Fill out your copyright notice in the Description page of Project Settings.


#include "PMainHUDWidget.h"

#include "Module/PCommonButton.h"
#include "Components/Button.h"
#include "PQuestHUDWidget.h"

void UPMainHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CommonButtonQuest)
	{
		CommonButtonQuest->GetButtonBG()->OnClicked.AddDynamic(this, &UPMainHUDWidget::OnButtonQuestClicked);
	}
}

void UPMainHUDWidget::OnButtonQuestClicked()
{
	OpenHUDWidget(TEXT("WBP_QuestHUD"), 0);
}