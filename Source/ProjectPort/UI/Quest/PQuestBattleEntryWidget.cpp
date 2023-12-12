// Fill out your copyright notice in the Description page of Project Settings.


#include "PQuestBattleEntryWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UPQuestBattleEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UPQuestBattleEntryWidget* Obj = Cast<UPQuestBattleEntryWidget>(ListItemObject);
	Index = Obj->Index;
	EntryData = Obj->EntryData;
	ParentWidget = Obj->ParentWidget;

	TextName->SetText(EntryData.TitleName);
	ImageSelected->SetVisibility(ESlateVisibility::Collapsed);
}

void UPQuestBattleEntryWidget::InitEntry(int32 EntryIndex, FPQuestBattleShowdowns Data, UPQuestBattleWidget* Parent)
{
	Index = EntryIndex;
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

void UPQuestBattleEntryWidget::NativeOnItemSelectionChanged(bool bIsSelected)
{
	ImageSelected->SetVisibility(bIsSelected ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
}

void UPQuestBattleEntryWidget::OnButtonClicked()
{
	ParentWidget->OnListClicked(EntryData, Index);
}
