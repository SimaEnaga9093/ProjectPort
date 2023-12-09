// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PUserWidget.h"

#include "PQuestBattleWidget.generated.h"

class UPCommonTab;

/**
 * Quest-Battle Widget
 */
UCLASS()
class PROJECTPORT_API UPQuestBattleWidget : public UPUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnTabClicked(int TabIndex);

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonTab> CommonTab;
};
