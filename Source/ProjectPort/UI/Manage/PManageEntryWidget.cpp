// Fill out your copyright notice in the Description page of Project Settings.


#include "PManageEntryWidget.h"

#include "../../Data/PContentCharacterInfo.h"
#include "../Module/PJobIcon.h"
#include "Components/TextBlock.h"

void UPManageEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UPManageEntryData* Obj = Cast<UPManageEntryData>(ListItemObject);
	EntryData = Obj->EntryData;

	JobIcon->UpdateJobType(EntryData.Job);
	TextName->SetText(FText::FromString(EntryData.Name));
}

void UPManageEntryWidget::NativeOnItemSelectionChanged(bool bIsSelected)
{
	//TODO
}
