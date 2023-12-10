// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PUserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "../../Data/PQuestBattleShowdowns.h"

#include "PQuestBattleEntryWidget.generated.h"

class UTextBlock;
class UButton;

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
	void InitEntry(FPQuestBattleShowdowns Data);

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnButtonClicked();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonBG;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText NameText;

	FPQuestBattleShowdowns EntryData;
};
