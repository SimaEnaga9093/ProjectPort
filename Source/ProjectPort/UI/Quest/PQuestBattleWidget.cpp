// Fill out your copyright notice in the Description page of Project Settings.


#include "PQuestBattleWidget.h"

#include "Engine/DataTable.h"
#include "UObject/ConstructorHelpers.h"
#include "../Module/PCommonTab.h"
#include "PQuestBattleEntryWidget.h"
#include "Components/ListView.h"

UPQuestBattleWidget::UPQuestBattleWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DataObject(TEXT("/Game/Data/DT_QuestBattleShowdowns"));
	if (DataObject.Succeeded())
	{
		UDataTable* DataTable = DataObject.Object;

		TArray<FName> Datas = DataTable->GetRowNames();
		for (int i = 0; i < Datas.Num(); i++)
		{
			const FString& ContextString = TEXT("UPQuestBattleWidget::NativePreConstruct");
			FPQuestBattleShowdowns* Data = DataTable->FindRow<FPQuestBattleShowdowns>(Datas[i], ContextString);

			if (!QuestBattleShowdowns.Contains(Data->Category))
				QuestBattleShowdowns.Add(Data->Category, FQuestBattleEntries());

			QuestBattleShowdowns[Data->Category].Entries.Add(*Data);
		}
	}
}

void UPQuestBattleWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void UPQuestBattleWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CommonTab)
	{
		CommonTab->OnClicked.AddDynamic(this, &UPQuestBattleWidget::OnTabClicked);
		CommonTab->OnTabClicked(0);
	}

	if (ListViewEntries)
		ListViewEntries->OnItemClicked().AddUObject(this, &UPQuestBattleWidget::OnListViewClicked);
}

void UPQuestBattleWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (CommonTab)
		CommonTab->OnClicked.RemoveDynamic(this, &UPQuestBattleWidget::OnTabClicked);

	if (ListViewEntries)
		ListViewEntries->OnItemClicked().Clear();
}

void UPQuestBattleWidget::OnTabClicked(int TabIndex)
{
	CurrentTab = TabIndex;
	UpdateListView();
}

void UPQuestBattleWidget::UpdateListView()
{
	ListViewEntries->ClearListItems();

	TArray<FPQuestBattleShowdowns> Datas = QuestBattleShowdowns[(EQuestBattleCategory)CurrentTab].Entries;
	for (int i = 0; i < Datas.Num(); i++)
	{
		UPQuestBattleEntryData* Item = NewObject<UPQuestBattleEntryData>();
		Item->EntryData = Datas[i];
		ListViewEntries->AddItem(Item);

		if (i == 0)
			OnListViewClicked(Item);
	}
}

void UPQuestBattleWidget::OnListViewClicked(UObject* Item)
{
	UPQuestBattleEntryData* Obj = Cast<UPQuestBattleEntryData>(Item);
	QuestBattleInfo->InitWidget(Obj->EntryData);

	ListViewEntries->SetSelectedItem(Item);
}
