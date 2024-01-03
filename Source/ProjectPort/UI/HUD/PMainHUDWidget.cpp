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
		CommonButtonQuest->GetButtonBG()->OnClicked.AddDynamic(this, &UPMainHUDWidget::OnButtonQuestClicked);

	if (CommonButtonManage)
		CommonButtonManage->GetButtonBG()->OnClicked.AddDynamic(this, &UPMainHUDWidget::OnButtonManageClicked);
}

void UPMainHUDWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (CommonButtonQuest)
		CommonButtonQuest->GetButtonBG()->OnClicked.RemoveAll(this);

	if (CommonButtonManage)
		CommonButtonManage->GetButtonBG()->OnClicked.RemoveAll(this);
}

void UPMainHUDWidget::OnButtonQuestClicked()
{
	GetPortGameMode()->OpenHUDWidget(TEXT("WBP_QuestHUD"), 0);
}

void UPMainHUDWidget::OnButtonManageClicked()
{
	GetPortGameMode()->OpenHUDWidget(TEXT("WBP_ManageHUD"), 0);
}
