// Fill out your copyright notice in the Description page of Project Settings.


#include "PQuestBattleEntryWidget.h"

#include "Components/TextBlock.h"
#include "Components/Image.h"

void UPQuestBattleEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UPQuestBattleEntryData* Obj = Cast<UPQuestBattleEntryData>(ListItemObject);
	EntryData = Obj->EntryData;

	TextName->SetText(EntryData.TitleName);
	ImageSelected->SetVisibility(ESlateVisibility::Collapsed);
}

void UPQuestBattleEntryWidget::NativeOnItemSelectionChanged(bool bIsSelected)
{
	ImageSelected->SetVisibility(bIsSelected ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
}
