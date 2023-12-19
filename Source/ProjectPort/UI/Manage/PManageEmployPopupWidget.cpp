// Fill out your copyright notice in the Description page of Project Settings.


#include "PManageEmployPopupWidget.h"

#include "Components/EditableText.h"
#include "Components/Button.h"
#include "../Module/PCommonButton.h"
#include "Components/TextBlock.h"
#include "../../ProjectPortGameModeBase.h"

#include "Kismet/GameplayStatics.h"
#include "../../Data/PPortSaveGame.h"
#include "UObject/ConstructorHelpers.h"

void UPManageEmployPopupWidget::OnOpen()
{
	SelectedJobType = EContentCharacterJob::E_Tanker;
	UpdateJobButtonState();
	
	//for (int i = 0; i < EditableTextStats.Num(); i++)
		//EditableTextStats[(EContentCharacterStat)i]->SetText(FText::AsNumber(0));
	UpdateRemainPoint();
}

void UPManageEmployPopupWidget::NativePreConstruct()
{
	ButtonJobs.Empty();
	ButtonJobs.Add(EContentCharacterJob::E_Tanker, ButtonJobTanker);
	ButtonJobs.Add(EContentCharacterJob::E_Melee, ButtonJobMelee);
	ButtonJobs.Add(EContentCharacterJob::E_Range, ButtonJobRange);
	ButtonJobs.Add(EContentCharacterJob::E_Healer, ButtonJobHealer);

	EditableTextStats.Empty();
	EditableTextStats.Add(EContentCharacterStat::E_STR, EditableTextSTR);
	EditableTextStats.Add(EContentCharacterStat::E_DEX, EditableTextDEX);
	EditableTextStats.Add(EContentCharacterStat::E_INT, EditableTextINT);
	EditableTextStats.Add(EContentCharacterStat::E_MND, EditableTextMND);

	InputtedStats.Empty();
	InputtedStats.Add(EContentCharacterStat::E_STR, 0);
	InputtedStats.Add(EContentCharacterStat::E_DEX, 0);
	InputtedStats.Add(EContentCharacterStat::E_INT, 0);
	InputtedStats.Add(EContentCharacterStat::E_MND, 0);
}

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
	InputtedName = Text;
}

void UPManageEmployPopupWidget::OnButtonJobTankerClicked()
{
	SelectedJobType = EContentCharacterJob::E_Tanker;
	UpdateJobButtonState();
}

void UPManageEmployPopupWidget::OnButtonJobMeleeClicked()
{
	SelectedJobType = EContentCharacterJob::E_Melee;
	UpdateJobButtonState();
}

void UPManageEmployPopupWidget::OnButtonJobRangeClicked()
{
	SelectedJobType = EContentCharacterJob::E_Range;
	UpdateJobButtonState();
}

void UPManageEmployPopupWidget::OnButtonJobHealerClicked()
{
	SelectedJobType = EContentCharacterJob::E_Healer;
	UpdateJobButtonState();
}

void UPManageEmployPopupWidget::OnEditableTextSTRChanged(const FText& Text)
{
	UpdateStatTotal(EContentCharacterStat::E_STR, Text);
}

void UPManageEmployPopupWidget::OnEditableTextDEXChanged(const FText& Text)
{
	UpdateStatTotal(EContentCharacterStat::E_DEX, Text);
}

void UPManageEmployPopupWidget::OnEditableTextINTChanged(const FText& Text)
{
	UpdateStatTotal(EContentCharacterStat::E_INT, Text);
}

void UPManageEmployPopupWidget::OnEditableTextMNDChanged(const FText& Text)
{
	UpdateStatTotal(EContentCharacterStat::E_MND, Text);
}

void UPManageEmployPopupWidget::OnCommonButtonEmployClicked()
{
	FText FailedReasonText = FText();
	if (RemainPoint > 0)
		FailedReasonText = FText::FromString(TEXT("Need to make Remain point to 0!"));
	if (InputtedName.IsEmpty())
		FailedReasonText = FText::FromString(TEXT("Need to set a Name!"));

	if (!FailedReasonText.IsEmpty())
	{
		GetPortGameMode()->OpenToastMessageWidget(FailedReasonText);
		return;
	}
/*
	if (UPPortSaveGame* SaveGameInstance = Cast<UPPortSaveGame>(UGameplayStatics::CreateSaveGameObject(UPPortSaveGame::StaticClass())))
	{
		FAsyncSaveGameToSlotDelegate OnSaved;
		OnSaved.BindUObject(this, &UPManageHUDWidget::OnSaveGameSaved);

		TArray<FPContentCharacterInfo> SaveGameDatas;
		SaveGameInstance->Characters = SaveGameDatas;

		UGameplayStatics::AsyncSaveGameToSlot(SaveGameInstance, TEXT("Default"), 0, OnSaved);
	}
*/
	ClosePopup();
}

void UPManageEmployPopupWidget::UpdateJobButtonState()
{
	for (int i = 0; i < ButtonJobs.Num(); i++)
	{
		EContentCharacterJob TargetJob = (EContentCharacterJob)i;
		ButtonJobs[TargetJob]->SetRenderOpacity(TargetJob == SelectedJobType ? 1.0f : 0.25f);
	}
}

void UPManageEmployPopupWidget::UpdateStatTotal(EContentCharacterStat ChangedStat, const FText& NewText)
{
	int newStat = FCString::Atof(*NewText.ToString());
	if (newStat > MaxStatPoint)
	{
		newStat = MaxStatPoint;
		EditableTextStats[ChangedStat]->SetText(FText::AsNumber(MaxStatPoint));
	}
	InputtedStats[ChangedStat] = newStat;

	UpdateRemainPoint();
}

void UPManageEmployPopupWidget::UpdateRemainPoint()
{
	RemainPoint = TotalPoint;
	for (int i = 0; i < InputtedStats.Num(); i++)
		RemainPoint -= InputtedStats[(EContentCharacterStat)i];

	FText ManageEmployRemainPointText = NSLOCTEXT("ManageEmploy", "RemainPoint", "Remain Point : {0}");
	TextRemainPoint->SetText(FText::Format(ManageEmployRemainPointText, RemainPoint));
}
