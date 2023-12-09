// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PUserWidget.h"

#include "PCommonTabEntry.generated.h"

class UPCommonButton;
class UPCommonTab;

/**
 * Module Common Tab Entry For Tab
 */
UCLASS()
class PROJECTPORT_API UPCommonTabEntry : public UPUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnButtonClicked();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButton;
	
	UPROPERTY()
	TSoftObjectPtr<UPCommonTab> ParentTab;

public:
	UFUNCTION()
	void InitTabEntry(UPCommonTab *Parent, int Index, FText Name);

	UFUNCTION()
	TSoftObjectPtr<UPCommonButton> GetCommonButton() { return CommonButton; }

	UPROPERTY()
	int TabIndex;
};
