// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../PUserWidget.h"
#include "PCommonButton.generated.h"

class USizeBox;
class UButton;
class UTextBlock;

/**
 * 
 */
UCLASS()
class PROJECTPORT_API UPCommonButton : public UPUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<USizeBox> SizeBoxBG;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonBG;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextMain;

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D WidthHeightOverride;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText MainText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float TextSize;
};
