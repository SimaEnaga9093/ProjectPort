// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PUserWidget.h"
#include "../../Data/PQuestBattleShowdowns.h"
#include "PQuestBattleInfoWidget.h"

#include "PQuestBattleWidget.generated.h"

class UPCommonTab;
class UDataTable;
class UListView;

USTRUCT()
struct FQuestBattleEntries
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	TArray<FPQuestBattleShowdowns> Entries;
};

/**
 * Quest-Battle Widget
 */
UCLASS()
class PROJECTPORT_API UPQuestBattleWidget : public UPUserWidget
{
	GENERATED_BODY()

public:
	UPQuestBattleWidget(const FObjectInitializer& ObjectInitializer);
	
	UFUNCTION()
	void OnListViewClicked(UObject* Item);

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnTabClicked(int TabIndex);

	UFUNCTION()
	void UpdateListView();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonTab> CommonTab;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UListView> ListViewEntries;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPQuestBattleInfoWidget> QuestBattleInfo;

	UPROPERTY()
	TMap<EQuestBattleCategory, FQuestBattleEntries> QuestBattleShowdowns;

	int CurrentTab;
};
