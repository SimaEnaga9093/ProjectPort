// Fill out your copyright notice in the Description page of Project Settings.


#include "PCommonTab.h"

#include "PCommonButton.h"
#include "PCommonTabEntry.h"
#include "Components/HorizontalBox.h"

void UPCommonTab::NativePreConstruct()
{
	Super::NativePreConstruct();

	HorizontalBoxEntries->ClearChildren();
	Entries.Reset();

	if (TabNames.Num() <= 0)
		return;

	const FString& Path = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/Module/WBP_CommonTabEntry.WBP_CommonTabEntry_C'");
	FSoftClassPath WidgetClassRef(Path);
	if (UClass* WidgetClass = WidgetClassRef.TryLoadClass<UPCommonTabEntry>())
	{
		for (int i = 0; i < TabNames.Num(); i++)
		{
			UPCommonTabEntry* EntryWidget = CreateWidget<UPCommonTabEntry>(GetWorld(), WidgetClass);
			EntryWidget->InitTabEntry(this, i, TabNames[i]);

			HorizontalBoxEntries->AddChild(EntryWidget);
			Entries.Add(EntryWidget);
		}
	}
}

void UPCommonTab::NativeDestruct()
{
	Super::NativeDestruct();

	HorizontalBoxEntries->ClearChildren();
	Entries.Reset();
}

void UPCommonTab::OnTabClicked(int NewIndex)
{
	TabIndex = NewIndex;
	
	for (int i = 0; i < TabNames.Num(); i++)
	{
		Entries[i]->GetCommonButton()->SetIsEnabled(i != TabIndex);
	}

	if (OnClicked.IsBound())
		OnClicked.Broadcast(TabIndex);
}
