// Fill out your copyright notice in the Description page of Project Settings.


#include "PManageInfoPopupWidget.h"

#include "../Module/PJobIcon.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "../Module/PCommonButton.h"
#include "../../ProjectPortGameModeBase.h"
#include "../Module/PCommonPopupWidget.h"
#include "Kismet/GameplayStatics.h"
#include "../../Data/PPortSaveGame.h"
#include "UObject/ConstructorHelpers.h"

void UPManageInfoPopupWidget::OnOpen()
{

}

void UPManageInfoPopupWidget::UpdateInfoPopup(FPContentCharacterInfo Info)
{
	CharacterInfo = Info;

	TextName->SetText(FText::FromString(Info.Name));
	FText CommonLevelText = NSLOCTEXT("Common", "Level", "LV.{0}");
	TextLevel->SetText(FText::Format(CommonLevelText, Info.Level));
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

void UPManageInfoPopupWidget::OnButtonBGClicked()
{
	ClosePopup();
}

void UPManageInfoPopupWidget::OnButtonRetirementClicked()
{
	UPCommonPopupWidget* PopupWidget = Cast<UPCommonPopupWidget>(GetPortGameMode()->OpenPopupWidget(TEXT("WBP_CommonPopup")));
	PopupWidget->InitCommonPopup(FText::FromString(TEXT("Alert")), FText::FromString(TEXT("Are you sure to Retire character and Remove from list?")), true);
	PopupWidget->GetCommonButtonConfirm()->OnClicked.AddDynamic(this, &UPManageInfoPopupWidget::OnRetirementPopupConfirmClicked);
}

void UPManageInfoPopupWidget::OnRetirementPopupConfirmClicked()
{
	FAsyncLoadGameFromSlotDelegate OnLoaded;
	OnLoaded.BindUObject(this, &UPManageInfoPopupWidget::OnSaveGameLoaded);
	UGameplayStatics::AsyncLoadGameFromSlot(TEXT("Default"), 0, OnLoaded);
}

void UPManageInfoPopupWidget::OnSaveGameLoaded(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData)
{
	UPPortSaveGame* SavedGame = Cast<UPPortSaveGame>(LoadedGameData);
	if (SavedGame)
	{
		FAsyncSaveGameToSlotDelegate OnSaved;
		OnSaved.BindUObject(this, &UPManageInfoPopupWidget::OnSaveGameSaved);

		SavedGame->Characters.Remove(CharacterInfo);

		UGameplayStatics::AsyncSaveGameToSlot(SavedGame, TEXT("Default"), 0, OnSaved);
	}
}

void UPManageInfoPopupWidget::OnSaveGameSaved(const FString& SlotName, const int32 UserIndex, bool bSuccess)
{
	ClosePopup();

	if (bSuccess)
		GetPortGameMode()->OpenToastMessageWidget(FText::FromString(TEXT("Retirement Success...")));
}

void UPManageInfoPopupWidget::OnButtonTrainClicked()
{
}
