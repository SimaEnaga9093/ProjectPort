// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PUserWidget.h"

#include "PHUDWidget.generated.h"

/**
 * Base HUD Widget
 */
UCLASS()
class PROJECTPORT_API UPHUDWidget : public UPUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText HUDNameText;

public:
	UFUNCTION()
	virtual void OnOpen();

	UFUNCTION()
	virtual void OnClose();

	UFUNCTION()
	virtual void OnBack();

	UFUNCTION()
	virtual bool HandleBackAction();

	UFUNCTION()
	const FText& GetHUDNameText() { return HUDNameText; }
};
