// Fill out your copyright notice in the Description page of Project Settings.


#include "PManageInfoPopupWidget.h"

#include "../Module/PJobIcon.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "../Module/PCommonButton.h"
#include "../../Data/PLocalText.h"
#include "../../ProjectPortGameModeBase.h"
#include "../Module/PCommonPopupWidget.h"
#include "Kismet/GameplayStatics.h"
#include "../../Data/PPortSaveGame.h"
#include "UObject/ConstructorHelpers.h"

void UPManageInfoPopupWidget::OnOpen()
{
	FAsyncLoadGameFromSlotDelegate OnLoaded;
	OnLoaded.BindLambda([&] (const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData) {
		SavedGame = Cast<UPPortSaveGame>(LoadedGameData);
	});

	UGameplayStatics::AsyncLoadGameFromSlot(TEXT("Default"), 0, OnLoaded);
}

void UPManageInfoPopupWidget::UpdateCharacterInfo(FPContentCharacterInfo Info)
{
	CharacterInfo = Info;

	RefreshWidget();
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

	if (CommonButtonRetirement)
		CommonButtonRetirement->GetButtonBG()->OnClicked.AddDynamic(this, &UPManageInfoPopupWidget::OnButtonRetirementClicked);
	if (CommonButtonTrain)
		CommonButtonTrain->GetButtonBG()->OnClicked.AddDynamic(this, &UPManageInfoPopupWidget::OnButtonTrainClicked);
}

void UPManageInfoPopupWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (ButtonBG)
		ButtonBG->OnClicked.RemoveAll(this);

	if (CommonButtonRetirement)
		CommonButtonRetirement->GetButtonBG()->OnClicked.RemoveAll(this);
	if (CommonButtonTrain)
		CommonButtonTrain->GetButtonBG()->OnClicked.RemoveAll(this);
}

void UPManageInfoPopupWidget::RefreshWidget()
{
	TextName->SetText(FText::FromString(CharacterInfo.Name));
	TextLevel->SetText(FText::Format(PLocalText::CommonLevel, CharacterInfo.Level));
	JobIcon->UpdateJobType(CharacterInfo.Job);

	for (int i = 0; i < TextStats.Num(); i++)
		TextStats[(EContentCharacterStat)i]->SetText(FText::AsNumber(CharacterInfo.Stats[(EContentCharacterStat)i]));
}

void UPManageInfoPopupWidget::OnButtonBGClicked()
{
	ClosePopup();
}

void UPManageInfoPopupWidget::OnButtonRetirementClicked()
{
	UPCommonPopupWidget* PopupWidget = Cast<UPCommonPopupWidget>(GetPortGameMode()->OpenPopupWidget(TEXT("WBP_CommonPopup")));
	PopupWidget->InitCommonPopup(PLocalText::CommonAlert, PLocalText::ManageInfoRetireConfirm, true);
	PopupWidget->GetCommonButtonConfirm()->OnClicked.AddDynamic(this, &UPManageInfoPopupWidget::OnRetirementPopupConfirmClicked);
}

void UPManageInfoPopupWidget::OnRetirementPopupConfirmClicked()
{
	SavedGame->Characters.Remove(CharacterInfo);

	FAsyncSaveGameToSlotDelegate OnSaved;
	OnSaved.BindLambda([&] (const FString& SlotName, const int32 UserIndex, bool bSuccess) {
		ClosePopup();

		if (bSuccess)
			GetPortGameMode()->OpenToastMessageWidget(PLocalText::ManageInfoRetireSuccess);
	});

	UGameplayStatics::AsyncSaveGameToSlot(SavedGame, TEXT("Default"), 0, OnSaved);
}

void UPManageInfoPopupWidget::OnButtonTrainClicked()
{
	int32 Index = SavedGame->Characters.Find(CharacterInfo);

	CharacterInfo.Level += 1;

	EContentCharacterStat TargetStat = (EContentCharacterStat)FMath::RandRange(0, 3);
	int IncreasedValue = FMath::RandRange(1, 3);
	CharacterInfo.Stats[TargetStat] += IncreasedValue;

	SavedGame->Characters[Index] = CharacterInfo;

	FAsyncSaveGameToSlotDelegate OnSaved;
	OnSaved.BindLambda([&, IncreasedValue] (const FString& SlotName, const int32 UserIndex, bool bSuccess) {
		RefreshWidget();

		if (bSuccess)
			GetPortGameMode()->OpenToastMessageWidget(FText::Format(PLocalText::ManageInfoTrainSuccess, PLocalText::CommonContentCharacterStat[(int)TargetStat], IncreasedValue));
	});

	UGameplayStatics::AsyncSaveGameToSlot(SavedGame, TEXT("Default"), 0, OnSaved);
}
