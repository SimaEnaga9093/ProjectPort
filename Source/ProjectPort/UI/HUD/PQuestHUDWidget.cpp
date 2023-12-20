// Fill out your copyright notice in the Description page of Project Settings.


#include "PQuestHUDWidget.h"

#include "../Module/PCommonButton.h"
#include "../Module/PCommonPopupWidget.h"
#include "Components/Button.h"
#include "../../ProjectPortGameModeBase.h"
#include "../PTopBarWidget.h"

UPQuestHUDWidget::UPQuestHUDWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	HUDNameText = FText::FromString("Quest");

	TabNames = {
		FText::FromString("Battle"),
		FText::FromString("Adventure"),
		FText::FromString("Craft")
	};
}

void UPQuestHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CommonButtonBattle)
		CommonButtonBattle->GetButtonBG()->OnClicked.AddDynamic(this, &UPQuestHUDWidget::OnCommonButtonBattleClicked);
	if (CommonButtonAdventure)
		CommonButtonAdventure->GetButtonBG()->OnClicked.AddDynamic(this, &UPQuestHUDWidget::OnCommonButtonAdventureClicked);
	if (CommonButtonCraft)
		CommonButtonCraft->GetButtonBG()->OnClicked.AddDynamic(this, &UPQuestHUDWidget::OnCommonButtonCraftClicked);
}

void UPQuestHUDWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (CommonButtonBattle)
		CommonButtonBattle->GetButtonBG()->OnClicked.RemoveAll(this);
	if (CommonButtonAdventure)
		CommonButtonAdventure->GetButtonBG()->OnClicked.RemoveAll(this);
	if (CommonButtonCraft)
		CommonButtonCraft->GetButtonBG()->OnClicked.RemoveAll(this);
}

void UPQuestHUDWidget::OnOpen()
{
	Super::OnOpen();

	TabIndex = EQuestHUDTabIndex::E_Battle;
	UpdateTabIndex();
}

void UPQuestHUDWidget::OnCommonButtonBattleClicked()
{
	TabIndex = EQuestHUDTabIndex::E_Battle;
	UpdateTabIndex();
}

void UPQuestHUDWidget::OnCommonButtonAdventureClicked()
{
	TabIndex = EQuestHUDTabIndex::E_Adventure;
	UpdateTabIndex();
}

void UPQuestHUDWidget::OnCommonButtonCraftClicked()
{
	TabIndex = EQuestHUDTabIndex::E_Craft;
	UpdateTabIndex();
}

void UPQuestHUDWidget::UpdateTabIndex()
{
	QuestBattle->SetVisibility(TabIndex == EQuestHUDTabIndex::E_Battle ? ESlateVisibility::SelfHitTestInvisible : ESlateVisibility::Collapsed);
	GetPortGameMode()->GetTopBarWidget()->SetNameText(TabNames[(uint8)TabIndex]);
}
