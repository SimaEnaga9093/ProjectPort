// Fill out your copyright notice in the Description page of Project Settings.


#include "PCommonTabEntry.h"

#include "PCommonButton.h"
#include "Components/Button.h"
#include "PCommonTab.h"

void UPCommonTabEntry::NativeConstruct()
{
	Super::NativeConstruct();

	if (CommonButton)
		CommonButton->GetButtonBG()->OnClicked.AddDynamic(this, &UPCommonTabEntry::OnButtonClicked);
}

void UPCommonTabEntry::NativeDestruct()
{
	Super::NativeDestruct();

	if (CommonButton)
		CommonButton->GetButtonBG()->OnClicked.RemoveDynamic(this, &UPCommonTabEntry::OnButtonClicked);
}

void UPCommonTabEntry::OnButtonClicked()
{
	ParentTab->OnTabClicked(TabIndex);
}

void UPCommonTabEntry::InitTabEntry(UPCommonTab* Parent, int Index, FText Name)
{
	ParentTab = Parent;
	TabIndex = Index;
	CommonButton->MainText = Name;
}
