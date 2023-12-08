// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PHUDWidget.h"

#include "PQuestHUDWidget.generated.h"

class UPCommonButton;

UENUM()
enum class EQuestHUDTabIndex : uint8
{
	E_Battle = 0,
	E_Adventure = 1,
	E_Craft = 2,
};

/**
 * Quest HUD
 */
UCLASS()
class PROJECTPORT_API UPQuestHUDWidget : public UPHUDWidget
{
	GENERATED_BODY()

public:
	UPQuestHUDWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	virtual void OnOpen() override;

	UFUNCTION()
	void OnCommonButtonBattleClicked();
	UFUNCTION()
	void OnCommonButtonAdventureClicked();
	UFUNCTION()
	void OnCommonButtonCraftClicked();

	UFUNCTION()
	void UpdateTabIndex();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonBattle;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonAdventure;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonCraft;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPUserWidget> QuestBattle;

	UPROPERTY()
	EQuestHUDTabIndex TabIndex = EQuestHUDTabIndex::E_Battle;

	UPROPERTY()
	TArray<FText> TabNames;
};
