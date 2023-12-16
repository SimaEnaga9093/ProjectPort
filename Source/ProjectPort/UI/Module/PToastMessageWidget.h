// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PUserWidget.h"

#include "PToastMessageWidget.generated.h"

class UTextBlock;
class UButton;

/**
 * Base Toast Message Widget
 */
UCLASS()
class PROJECTPORT_API UPToastMessageWidget : public UPUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UFUNCTION()
	void OnButtonBGClicked();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextMessage;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonBG;

	float LifeTimer = 0.0f;

	bool IsMessageShowned;

public:
	UFUNCTION()
	void OpenToastMessage();

	UFUNCTION()
	void CloaseToastMessage();

	UFUNCTION()
	const bool IsShowned() { return IsMessageShowned; }

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText MessageText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float LifeTime;
};
