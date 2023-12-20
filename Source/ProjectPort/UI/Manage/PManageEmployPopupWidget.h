// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PPopupWidget.h"
#include "../../Data/PContentCharacterInfo.h"

#include "PManageEmployPopupWidget.generated.h"

class UEditableText;
class UButton;
class UTextBlock;
class UPCommonButton;

/**
 * Manage - Employ Popup Widget
 */
UCLASS()
class PROJECTPORT_API UPManageEmployPopupWidget : public UPPopupWidget
{
	GENERATED_BODY()

public:
	virtual void OnOpen() override;

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnEditableTextNameChanged(const FText& Text);

	UFUNCTION()
	void OnButtonJobTankerClicked();
	UFUNCTION()
	void OnButtonJobMeleeClicked();
	UFUNCTION()
	void OnButtonJobRangeClicked();
	UFUNCTION()
	void OnButtonJobHealerClicked();

	UFUNCTION()
	void OnEditableTextSTRChanged(const FText& Text);
	UFUNCTION()
	void OnEditableTextDEXChanged(const FText& Text);
	UFUNCTION()
	void OnEditableTextINTChanged(const FText& Text);
	UFUNCTION()
	void OnEditableTextMNDChanged(const FText& Text);

	UFUNCTION()
	void OnCommonButtonEmployClicked();

	UFUNCTION()
	void OnSaveGameLoaded(const FString& SlotName, const int32 UserIndex, USaveGame* LoadedGameData);
	UFUNCTION()
	void OnSaveGameSaved(const FString& SlotName, const int32 UserIndex, bool bSuccess);

	UFUNCTION()
	void UpdateJobButtonState();

	UFUNCTION()
	void UpdateStatTotal(EContentCharacterStat ChangedStat, const FText& NewText);

	UFUNCTION()
	void UpdateRemainPoint();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UEditableText> EditableTextName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonJobTanker;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonJobMelee;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonJobRange;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonJobHealer;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UEditableText> EditableTextSTR;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UEditableText> EditableTextDEX;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UEditableText> EditableTextINT;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UEditableText> EditableTextMND;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextRemainPoint;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonEmploy;

	UPROPERTY()
	TMap<EContentCharacterJob, TSoftObjectPtr<UButton>> ButtonJobs;

	UPROPERTY()
	TMap<EContentCharacterStat, TSoftObjectPtr<UEditableText>> EditableTextStats;

	UPROPERTY()
	FText InputtedName;

	UPROPERTY()
	EContentCharacterJob SelectedJobType;

	UPROPERTY()
	TMap<EContentCharacterStat, int> InputtedStats;

	const int TotalPoint = 50;
	const int MaxStatPoint = 20;

	int RemainPoint;
};
