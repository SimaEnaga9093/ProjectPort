// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PHUDWidget.h"

#include "PQuestHUDWidget.generated.h"

class UPCommonButton;

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

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonBattle;

	UFUNCTION()
	void OnCommonButtonBattleClicked();
};
