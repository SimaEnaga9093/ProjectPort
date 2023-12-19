// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PPopupWidget.h"

#include "PManageEmployPopupWidget.generated.h"

class UEditableTextBox;
class UButton;
class UPCommonButton;

/**
 * Manage - Employ Popup Widget
 */
UCLASS()
class PROJECTPORT_API UPManageEmployPopupWidget : public UPPopupWidget
{
	GENERATED_BODY()

protected:
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

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UEditableTextBox> EditableTextName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonJobTanker;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonJobMelee;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonJobRange;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonJobHealer;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UEditableTextBox> EditableTextSTR;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UEditableTextBox> EditableTextDEX;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UEditableTextBox> EditableTextINT;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UEditableTextBox> EditableTextMND;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonEmploy;
};
