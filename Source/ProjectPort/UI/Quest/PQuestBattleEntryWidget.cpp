// Fill out your copyright notice in the Description page of Project Settings.


#include "PQuestBattleEntryWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"

void UPQuestBattleEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UPQuestBattleEntryWidget* Obj = Cast<UPQuestBattleEntryWidget>(ListItemObject);
	EntryData = Obj->EntryData;
	ParentWidget = Obj->ParentWidget;

	TextName->SetText(EntryData.TitleName);
}

void UPQuestBattleEntryWidget::InitEntry(FPQuestBattleShowdowns Data, UPQuestBattleWidget* Parent)
{
	EntryData = Data;
	ParentWidget = Parent;
}

void UPQuestBattleEntryWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ButtonBG)
		ButtonBG->OnClicked.AddDynamic(this, &UPQuestBattleEntryWidget::OnButtonClicked);
}

void UPQuestBattleEntryWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (ButtonBG)
		ButtonBG->OnClicked.RemoveDynamic(this, &UPQuestBattleEntryWidget::OnButtonClicked);
}

void UPQuestBattleEntryWidget::OnButtonClicked()
{
	ParentWidget->OnListClicked(EntryData);
}
