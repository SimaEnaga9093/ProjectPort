// Fill out your copyright notice in the Description page of Project Settings.


#include "PQuestBattleWidget.h"

#include "../Module/PCommonTab.h"
#include "../../ProjectPortGameModeBase.h"
#include "../Module/PCommonPopupWidget.h"

void UPQuestBattleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CommonTab)
		CommonTab->OnClicked.AddDynamic(this, &UPQuestBattleWidget::OnTabClicked);
}

void UPQuestBattleWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (CommonTab)
		CommonTab->OnClicked.RemoveDynamic(this, &UPQuestBattleWidget::OnTabClicked);
}

void UPQuestBattleWidget::OnTabClicked(int TabIndex)
{
	UPCommonPopupWidget* Popup = Cast<UPCommonPopupWidget>(GetPortGameMode()->OpenPopupWidget(TEXT("WBP_CommonPopup")));
	Popup->InitCommonPopup(FText::FromString("NOTICE"), FText::FromString(FString::FromInt(TabIndex)), false);
}
