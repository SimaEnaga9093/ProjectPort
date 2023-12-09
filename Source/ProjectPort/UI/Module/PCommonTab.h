// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "UObject/ObjectMacros.h"
#include "PUserWidget.h"

#include "PCommonTab.generated.h"

class UHorizontalBox;
class UPCommonTabEntry;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCommonTabClicked, int, Index);

/**
 * Module Common Tab With horizontal buttons
 */
UCLASS()
class PROJECTPORT_API UPCommonTab : public UPUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeDestruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UHorizontalBox> HorizontalBoxEntries;

	UPROPERTY()
	TArray<TSoftObjectPtr<UPCommonTabEntry>> Entries;

	UPROPERTY()
	int TabIndex = 1;

public:
	UFUNCTION()
	void OnTabClicked(int NewIndex);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<FText> TabNames;

	UPROPERTY()
	FOnCommonTabClicked OnClicked;
};
