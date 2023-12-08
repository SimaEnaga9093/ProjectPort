// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PHUDWidget.h"

#include "PMainHUDWidget.generated.h"

class UPCommonButton;

/**
 * Main HUD of project
 */
UCLASS()
class PROJECTPORT_API UPMainHUDWidget : public UPHUDWidget
{
	GENERATED_BODY()

public:
	UPMainHUDWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnButtonQuestClicked();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonQuest;
};
