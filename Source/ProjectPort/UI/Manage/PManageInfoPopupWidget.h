// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PPopupWidget.h"
#include "../../Data/PContentCharacterInfo.h"

#include "PManageInfoPopupWidget.generated.h"

class UButton;
class UPJobIcon;
class UTextBlock;
class UPCommonButton;

class UPPortSaveGame;

/**
 * Manage - Info Popup Widget
 */
UCLASS()
class PROJECTPORT_API UPManageInfoPopupWidget : public UPPopupWidget
{
	GENERATED_BODY()

public:
	virtual void OnOpen() override;
	void UpdateCharacterInfo(FPContentCharacterInfo Info);

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void RefreshWidget();

	UFUNCTION()
	void OnButtonBGClicked();

	UFUNCTION()
	void OnButtonRetirementClicked();
	UFUNCTION()
	void OnRetirementPopupConfirmClicked();

	UFUNCTION()
	void OnButtonTrainClicked();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonBG;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextName;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextLevel;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPJobIcon> JobIcon;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextSTR;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextDEX;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextINT;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextMND;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonRetirement;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonTrain;

	UPROPERTY()
	TMap<EContentCharacterStat, TSoftObjectPtr<UTextBlock>> TextStats;

	UPROPERTY()
	FPContentCharacterInfo CharacterInfo;

private:
	UPROPERTY()
	UPPortSaveGame* SavedGame;
};
