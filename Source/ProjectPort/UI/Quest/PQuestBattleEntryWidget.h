// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PUserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "../../Data/PQuestBattleShowdowns.h"
#include "PQuestBattleWidget.h"

#include "PQuestBattleEntryWidget.generated.h"

class UTextBlock;
class UButton;
class UImage;

/**
 * Quest-Battle list entry Widget
 */
UCLASS()
class PROJECTPORT_API UPQuestBattleEntryWidget : public UPUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	
	UFUNCTION()
	void InitEntry(int32 EntryIndex, FPQuestBattleShowdowns Data, UPQuestBattleWidget* Parent);

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeOnItemSelectionChanged(bool bIsSelected) override;

	UFUNCTION()
	void OnButtonClicked();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonBG;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UImage> ImageSelected;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText NameText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsSelected;

	int32 Index;

	FPQuestBattleShowdowns EntryData;

	UPROPERTY()
	TSoftObjectPtr<UPQuestBattleWidget> ParentWidget;
};
