// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PUserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "../../Data/PContentCharacterInfo.h"

#include "PManageEntryWidget.generated.h"

class UImage;
class UTextBlock;

UCLASS()
class PROJECTPORT_API UPManageEntryData : public UObject
{
	GENERATED_BODY()

public:
	UPManageEntryData() {}

	FPContentCharacterInfo EntryData;
};

/**
 * Manage list entry Widget
 */
UCLASS()
class PROJECTPORT_API UPManageEntryWidget : public UPUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	virtual void NativeOnItemSelectionChanged(bool bIsSelected) override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UImage> ImageIcon;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextName;

	FPContentCharacterInfo EntryData;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UTexture2D> IconImage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText NameText;
};
