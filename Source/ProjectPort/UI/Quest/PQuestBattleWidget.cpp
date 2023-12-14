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

	const FString& Path = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/Battle/WBP_QuestBattleEntry.WBP_QuestBattleEntry_C'");
	FSoftClassPath WidgetClassRef(Path);
	if (UClass* WidgetClass = WidgetClassRef.TryLoadClass<UPQuestBattleEntryWidget>())
	{
		for (int i = 0; i < Datas.Num(); i++)
		{
			UPQuestBattleEntryWidget* EntryWidget = CreateWidget<UPQuestBattleEntryWidget>(GetWorld(), WidgetClass);
			EntryWidget->InitEntry(i, Datas[i], this);
			ListViewEntries->AddItem(EntryWidget);

			if (i == 0)
			{
				ListViewEntries->SetSelectedItem(EntryWidget);
				OnListViewClicked(EntryWidget);
			}
		}
	}
}

void UPQuestBattleWidget::OnListClicked(FPQuestBattleShowdowns EntryData, int32 Index)
{
	QuestBattleInfo->InitWidget(EntryData);
	ListViewEntries->SetSelectedIndex(Index);
}

void UPQuestBattleWidget::OnListViewClicked(UObject* Item)
{
	UPQuestBattleEntryWidget* Obj = Cast<UPQuestBattleEntryWidget>(Item);
	const FPQuestBattleShowdowns& EntryData = Obj->GetEntryData();

	QuestBattleInfo->InitWidget(EntryData);
}
