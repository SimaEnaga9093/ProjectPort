// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PUserWidget.h"

#include "PCommonButton.generated.h"

class USizeBox;
class UButton;
class UTextBlock;

/**
 * Module Common button with text
 */
UCLASS()
class PROJECTPORT_API UPCommonButton : public UPUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<USizeBox> SizeBoxBG;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonBG;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextMain;

	UFUNCTION()
	void OnButtoBGClicked();

	bool ActivateInputDelay = false;
	float InputDelayTimer = 0.0f;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D WidthHeightOverride;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText MainText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TextSize;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float InputDelaySec = 1.0f;

	UFUNCTION()
	TSoftObjectPtr<UButton> GetButtonBG() { return ButtonBG; }
};
