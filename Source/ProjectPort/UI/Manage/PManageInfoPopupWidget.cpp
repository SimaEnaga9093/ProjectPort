// Fill out your copyright notice in the Description page of Project Settings.


#include "PManageInfoPopupWidget.h"

#include "Components/EditableText.h"
#include "Components/Button.h"
#include "../Module/PCommonButton.h"
#include "Components/TextBlock.h"
#include "../../ProjectPortGameModeBase.h"

void UPManageInfoPopupWidget::OnOpen()
{

}

void UPManageInfoPopupWidget::NativePreConstruct()
{

}

void UPManageInfoPopupWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ButtonBG)
		ButtonBG->OnClicked.AddDynamic(this, &UPManageInfoPopupWidget::OnButtonBGClicked);
}

void UPManageInfoPopupWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (ButtonBG)
		ButtonBG->OnClicked.RemoveAll(this);
}

void UPManageInfoPopupWidget::OnButtonBGClicked()
{
	ClosePopup();
}
