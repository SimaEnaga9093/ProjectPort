// Fill out your copyright notice in the Description page of Project Settings.


#include "PManageEntryWidget.h"

#include "../../Data/PContentCharacterInfo.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UPManageEntryWidget::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UPManageEntryData* Obj = Cast<UPManageEntryData>(ListItemObject);
	EntryData = Obj->EntryData;

	ImageIcon->SetBrushFromTexture(EntryData.IconImage.LoadSynchronous());
	TextName->SetText(FText::FromString(EntryData.Name));
}

void UPManageEntryWidget::NativeOnItemSelectionChanged(bool bIsSelected)
{
	//TODO
}
