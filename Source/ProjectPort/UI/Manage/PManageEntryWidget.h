// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PUserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "../../Data/PContentCharacterInfo.h"

#include "PManageEntryWidget.generated.h"

class UPJobIcon;
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

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPJobIcon> JobIcon;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextName;

	FPContentCharacterInfo EntryData;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<EContentCharacterJob, TSoftObjectPtr<UTexture2D>> IconJobImages;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText NameText;
};
