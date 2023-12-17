// Fill out your copyright notice in the Description page of Project Settings.


#include "PManageHUDWidget.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DataTable.h"
#include "UObject/ConstructorHelpers.h"
#include "../../Data/PPortSaveGame.h"

UPManageHUDWidget::UPManageHUDWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	HUDNameText = FText::FromString("Manage");

	static ConstructorHelpers::FObjectFinder<UDataTable> DataObject(TEXT("/Game/Data/DT_ContentCharacterInfo"));
	if (DataObject.Succeeded())
	{
		DataTable = DataObject.Object;
	}
}

void UPManageHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (CommonButtonConfirm)
		CommonButtonConfirm->GetButtonBG()->OnClicked.AddDynamic(this, &UPManageHUDWidget::OnButtonConfirmClicked);
}

void UPManageHUDWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (CommonButtonConfirm)
		CommonButtonConfirm->GetButtonBG()->OnClicked.RemoveDynamic(this, &UPManageHUDWidget::OnButtonConfirmClicked);
}

void UPManageHUDWidget::OnOpen()
{
	Super::OnOpen();

	FAsyncLoadGameFromSlotDelegate OnLoaded;
	OnLoaded.BindUObject(this, &UPManageHUDWidget::OnSaveGameLoaded);

	UGameplayStatics::AsyncLoadGameFromSlot(TEXT("Default"), 0, OnLoaded);
}

void UPManageHUDWidget::OnSaveGameLoaded(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData)
{
	// TODO
	UPPortSaveGame* SaveGame = Cast<UPPortSaveGame>(LoadedGameData);

	for (int i = 0; i < SaveGame->Characters.Num(); i++)
	{
		FPContentCharacterInfo r = SaveGame->Characters[i];
		UE_LOG(LogTemp, Log, TEXT("%s %d"), *r.Name, (int)r.Job);
	}
}

void UPManageHUDWidget::OnSaveGameSaved(const FString& SlotName, const int32 UserIndex, bool bSuccess)
{
	// TODO
}

void UPManageHUDWidget::OnButtonConfirmClicked()
{
	if (UPPortSaveGame* SaveGameInstance = Cast<UPPortSaveGame>(UGameplayStatics::CreateSaveGameObject(UPPortSaveGame::StaticClass())))
	{
		FAsyncSaveGameToSlotDelegate OnSaved;
		OnSaved.BindUObject(this, &UPManageHUDWidget::OnSaveGameSaved);

		TArray<FPContentCharacterInfo> SaveGameDatas;

		// TODO
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
