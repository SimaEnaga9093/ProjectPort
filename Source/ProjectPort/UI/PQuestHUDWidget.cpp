// Fill out your copyright notice in the Description page of Project Settings.


#include "PQuestHUDWidget.h"

#include "Module/PCommonButton.h"
#include "Module/PCommonPopupWidget.h"
#include "Components/Button.h"
#include "../ProjectPortGameModeBase.h"

void UPQuestHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CommonButtonBattle)
	{
		CommonButtonBattle->GetButtonBG()->OnClicked.AddDynamic(this, &UPQuestHUDWidget::OnCommonButtonBattleClicked);
	}
}

void UPQuestHUDWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (CommonButtonBattle)
	{
		CommonButtonBattle->GetButtonBG()->OnClicked.RemoveDynamic(this, &UPQuestHUDWidget::OnCommonButtonBattleClicked);
	}
}

void UPQuestHUDWidget::OnCommonButtonBattleClicked()
{
	UPCommonPopupWidget* Popup = Cast<UPCommonPopupWidget>(GetPortGameMode()->OpenPopupWidget(TEXT("WBP_CommonPopup")));
	Popup->InitCommonPopup(FText::FromString("NOTICE"), FText::FromString("Not Developed Yet"), false);
}
