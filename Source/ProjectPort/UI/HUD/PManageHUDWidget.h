// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PHUDWidget.h"
#include "../Module/PCommonButton.h"
#include "../../Data/PContentCharacterInfo.h"

#include "PManageHUDWidget.generated.h"

class UTileView;

/**
 * Manage HUD
 */
UCLASS()
class PROJECTPORT_API UPManageHUDWidget : public UPHUDWidget
{
	GENERATED_BODY()

public:
	UPManageHUDWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	virtual void OnOpen() override;

	UFUNCTION()
	void InitPopupWidget();

	UFUNCTION()
	void OnSaveGameLoaded(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData);

	UFUNCTION()
	void OnSaveGameSaved(const FString& SlotName, const int32 UserIndex, bool bSuccess);

	UFUNCTION()
	void OnButtonConfirmClicked();
	UFUNCTION()
	void OnButtonEmployClicked();
	UFUNCTION()
	void OnEmployPopupClosed();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTileView> TileViewEntries;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonConfirm;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonEmploy;

	UDataTable* DataTable;
};
