// Fill out your copyright notice in the Description page of Project Settings.


#include "PCommonPopupWidget.h"

#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "PCommonButton.h"

void UPCommonPopupWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	UpdatePopup();
}

void UPCommonPopupWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CommonButtonConfirm)
		CommonButtonConfirm->GetButtonBG()->OnClicked.AddDynamic(this, &UPPopupWidget::ClosePopup);
}

void UPCommonPopupWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (CommonButtonConfirm)
		CommonButtonConfirm->GetButtonBG()->OnClicked.RemoveDynamic(this, &UPPopupWidget::ClosePopup);
}

void UPCommonPopupWidget::UpdatePopup()
{
	// Update Texts
	TextTitle->SetText(TitleText);
	TextComment->SetText(CommentText);

	CommonButtonCancel->SetVisibility(ShowCancelButton ? ESlateVisibility::Visible : ESlateVisibility::Collapsed);
}

void UPCommonPopupWidget::InitCommonPopup(FText _TitleText, FText _CommentText, bool _ShowCancelButton)
{
	TitleText = _TitleText;
	CommentText = _CommentText;
	ShowCancelButton = _ShowCancelButton;

	UpdatePopup();
}
