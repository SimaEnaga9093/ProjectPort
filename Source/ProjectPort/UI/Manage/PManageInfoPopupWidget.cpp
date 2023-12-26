// Fill out your copyright notice in the Description page of Project Settings.


#include "PManageInfoPopupWidget.h"

#include "../Module/PJobIcon.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "../Module/PCommonButton.h"
#include "../../ProjectPortGameModeBase.h"

void UPManageInfoPopupWidget::OnOpen()
{

}

void UPManageInfoPopupWidget::UpdateInfoPopup(FPContentCharacterInfo Info)
{
	TextName->SetText(FText::FromString(Info.Name));
	JobIcon->UpdateJobType(Info.Job);

	for (int i = 0; i < TextStats.Num(); i++)
		TextStats[(EContentCharacterStat)i]->SetText(FText::AsNumber(Info.Stats[(EContentCharacterStat)i]));
}

void UPManageInfoPopupWidget::NativePreConstruct()
{
	TextStats.Empty();
	TextStats.Add(EContentCharacterStat::E_STR, TextSTR);
	TextStats.Add(EContentCharacterStat::E_DEX, TextDEX);
	TextStats.Add(EContentCharacterStat::E_INT, TextINT);
	TextStats.Add(EContentCharacterStat::E_MND, TextMND);
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
