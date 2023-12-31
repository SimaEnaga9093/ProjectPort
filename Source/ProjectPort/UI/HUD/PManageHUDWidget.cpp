// Fill out your copyright notice in the Description page of Project Settings.


#include "PManageHUDWidget.h"

#include "Components/Button.h"
#include "Components/TileView.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DataTable.h"
#include "../../Data/PPortSaveGame.h"
#include "../Manage/PManageEntryWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "../../ProjectPortGameModeBase.h"
#include "../Module/PPopupWidget.h"
#include "../Manage/PManageInfoPopupWidget.h"
#include "../../Data/PLocalText.h"

UPManageHUDWidget::UPManageHUDWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	HUDNameText = FText::FromString("Manage");

	static ConstructorHelpers::FObjectFinder<UDataTable> DataObject(TEXT("/Game/Data/DT_ContentCharacterInfo"));
	if (DataObject.Succeeded())
		DataTable = DataObject.Object;
}

void UPManageHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (TileViewEntries)
		TileViewEntries->OnItemClicked().AddUObject(this, &UPManageHUDWidget::OnListViewClicked);

	if (CommonButtonReset)
		CommonButtonReset->GetButtonBG()->OnClicked.AddDynamic(this, &UPManageHUDWidget::OnButtonResetClicked);
	if (CommonButtonEmploy)
		CommonButtonEmploy->GetButtonBG()->OnClicked.AddDynamic(this, &UPManageHUDWidget::OnButtonEmployClicked);
}

void UPManageHUDWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (TileViewEntries)
		TileViewEntries->OnItemClicked().Clear();

	if (CommonButtonReset)
		CommonButtonReset->GetButtonBG()->OnClicked.RemoveAll(this);
	if (CommonButtonEmploy)
		CommonButtonEmploy->GetButtonBG()->OnClicked.RemoveAll(this);
}

void UPManageHUDWidget::OnOpen()
{
	Super::OnOpen();

	InitPopupWidget();
}

void UPManageHUDWidget::InitPopupWidget()
{
	FAsyncLoadGameFromSlotDelegate OnLoaded;
	OnLoaded.BindLambda([&] (const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData) {
		TileViewEntries->ClearListItems();

		UPPortSaveGame* SaveGame = Cast<UPPortSaveGame>(LoadedGameData);
		for (int i = 0; i < SaveGame->Characters.Num(); i++)
		{
			UPManageEntryData* Item = NewObject<UPManageEntryData>();
			Item->EntryData = SaveGame->Characters[i];
			TileViewEntries->AddItem(Item);
		}
	});

	UGameplayStatics::AsyncLoadGameFromSlot(TEXT("Default"), 0, OnLoaded);
}

void UPManageHUDWidget::OnListViewClicked(UObject* Item)
{
	UPManageEntryData* Obj = Cast<UPManageEntryData>(Item);

	UPManageInfoPopupWidget* PopupWidget = Cast<UPManageInfoPopupWidget>(GetPortGameMode()->OpenPopupWidget(TEXT("WBP_ManageInfoPopup")));
	PopupWidget->UpdateCharacterInfo(Obj->EntryData);
	PopupWidget->OnPopupClosed.AddDynamic(this, &UPManageHUDWidget::InitPopupWidget);
}

void UPManageHUDWidget::OnButtonResetClicked()
{
	if (UPPortSaveGame* SaveGameInstance = Cast<UPPortSaveGame>(UGameplayStatics::CreateSaveGameObject(UPPortSaveGame::StaticClass())))
	{
		FAsyncSaveGameToSlotDelegate OnSaved;
		OnSaved.BindLambda([&] (const FString& SlotName, const int32 UserIndex, bool bSuccess) {
			if (bSuccess)
				GetPortGameMode()->OpenToastMessageWidget(PLocalText::ManageResetSuccess);

			InitPopupWidget();
		});

		TArray<FPContentCharacterInfo> SaveGameDatas;
		if (DataTable)
		{
			TArray<FName> Datas = DataTable->GetRowNames();
			for (int i = 0; i < Datas.Num(); i++)
			{
				const FString& ContextString = TEXT("UPManageHUDWidget::OnButtonConfirmClicked");
				FPContentCharacterInfo Data = *DataTable->FindRow<FPContentCharacterInfo>(Datas[i], ContextString);

				SaveGameDatas.Add(Data);
			}
		}
		SaveGameInstance->Characters = SaveGameDatas;

		UGameplayStatics::AsyncSaveGameToSlot(SaveGameInstance, TEXT("Default"), 0, OnSaved);
	}
}

void UPManageHUDWidget::OnButtonEmployClicked()
{
	UPPopupWidget* PopupWidget = GetPortGameMode()->OpenPopupWidget(TEXT("WBP_ManageEmployPopup"));
	PopupWidget->OnPopupClosed.AddDynamic(this, &UPManageHUDWidget::OnEmployPopupClosed);
}

void UPManageHUDWidget::OnEmployPopupClosed()
{
	InitPopupWidget();
}
