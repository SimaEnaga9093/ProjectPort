// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PUserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "../../Data/PQuestBattleShowdowns.h"
#include "PQuestBattleWidget.h"

#include "PQuestBattleEntryWidget.generated.h"

class UTextBlock;
class UImage;

UCLASS()
class PROJECTPORT_API UPQuestBattleEntryData : public UObject
{
	GENERATED_BODY()

public:
	UPQuestBattleEntryData() {}

	FPQuestBattleShowdowns EntryData;
};

/**
 * Quest-Battle list entry Widget
 */
UCLASS()
class PROJECTPORT_API UPQuestBattleEntryWidget : public UPUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	virtual void NativeOnItemSelectionChanged(bool bIsSelected) override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UImage> ImageSelected;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText NameText;

	FPQuestBattleShowdowns EntryData;
};
