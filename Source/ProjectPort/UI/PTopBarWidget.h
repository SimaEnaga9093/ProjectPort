// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Module/PUserWidget.h"

#include "PTopBarWidget.generated.h"

class UButton;
class UTextBlock;

/**
 * Top bar Widget
 */
UCLASS()
class PROJECTPORT_API UPTopBarWidget : public UPUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void OnButtonBackClicked();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonBack;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextName;

public:
	UFUNCTION()
	void SetNameText(const FText& Text);
};
