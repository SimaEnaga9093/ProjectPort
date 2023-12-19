// Fill out your copyright notice in the Description page of Project Settings.


#include "PManageEmployPopupWidget.h"

#include "Components/EditableTextBox.h"
#include "Components/Button.h"
#include "../Module/PCommonButton.h"

void UPManageEmployPopupWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (EditableTextName)
		EditableTextName->OnTextChanged.AddDynamic(this, &UPManageEmployPopupWidget::OnEditableTextNameChanged);

	if (ButtonJobTanker)
		ButtonJobTanker->OnClicked.AddDynamic(this, &UPManageEmployPopupWidget::OnButtonJobTankerClicked);
	if (ButtonJobMelee)
		ButtonJobMelee->OnClicked.AddDynamic(this, &UPManageEmployPopupWidget::OnButtonJobMeleeClicked);
	if (ButtonJobRange)
		ButtonJobRange->OnClicked.AddDynamic(this, &UPManageEmployPopupWidget::OnButtonJobRangeClicked);
	if (ButtonJobHealer)
		ButtonJobHealer->OnClicked.AddDynamic(this, &UPManageEmployPopupWidget::OnButtonJobHealerClicked);

	if (EditableTextSTR)
		EditableTextSTR->OnTextChanged.AddDynamic(this, &UPManageEmployPopupWidget::OnEditableTextSTRChanged);
	if (EditableTextDEX)
		EditableTextDEX->OnTextChanged.AddDynamic(this, &UPManageEmployPopupWidget::OnEditableTextDEXChanged);
	if (EditableTextINT)
		EditableTextINT->OnTextChanged.AddDynamic(this, &UPManageEmployPopupWidget::OnEditableTextINTChanged);
	if (EditableTextMND)
		EditableTextMND->OnTextChanged.AddDynamic(this, &UPManageEmployPopupWidget::OnEditableTextMNDChanged);

	if (CommonButtonEmploy)
		CommonButtonEmploy->GetButtonBG()->OnClicked.AddDynamic(this, &UPManageEmployPopupWidget::OnCommonButtonEmployClicked);
}

void UPManageEmployPopupWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (EditableTextName)
		EditableTextName->OnTextChanged.RemoveAll(this);

	if (ButtonJobTanker)
		ButtonJobTanker->OnClicked.RemoveAll(this);
	if (ButtonJobMelee)
		ButtonJobMelee->OnClicked.RemoveAll(this);
	if (ButtonJobRange)
		ButtonJobRange->OnClicked.RemoveAll(this);
	if (ButtonJobHealer)
		ButtonJobHealer->OnClicked.RemoveAll(this);

	if (EditableTextSTR)
		EditableTextSTR->OnTextChanged.RemoveAll(this);
	if (EditableTextDEX)
		EditableTextDEX->OnTextChanged.RemoveAll(this);
	if (EditableTextINT)
		EditableTextINT->OnTextChanged.RemoveAll(this);
	if (EditableTextMND)
		EditableTextMND->OnTextChanged.RemoveAll(this);

	if (CommonButtonEmploy)
		CommonButtonEmploy->GetButtonBG()->OnClicked.RemoveAll(this);
}

void UPManageEmployPopupWidget::OnEditableTextNameChanged(const FText& Text)
{
}

void UPManageEmployPopupWidget::OnButtonJobTankerClicked()
{
}

void UPManageEmployPopupWidget::OnButtonJobMeleeClicked()
{
}

void UPManageEmployPopupWidget::OnButtonJobRangeClicked()
{
}

void UPManageEmployPopupWidget::OnButtonJobHealerClicked()
{
}

void UPManageEmployPopupWidget::OnEditableTextSTRChanged(const FText& Text)
{
}

void UPManageEmployPopupWidget::OnEditableTextDEXChanged(const FText& Text)
{
}

void UPManageEmployPopupWidget::OnEditableTextINTChanged(const FText& Text)
{
}

void UPManageEmployPopupWidget::OnEditableTextMNDChanged(const FText& Text)
{
}

void UPManageEmployPopupWidget::OnCommonButtonEmployClicked()
{
}
