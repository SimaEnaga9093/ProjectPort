// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PPopupWidget.h"
#include "PCommonButton.h"

#include "PCommonPopupWidget.generated.h"

class USizeBox;
class UTextBlock;
class UButton;

/**
 * Common and simple Popup Widget
 */
UCLASS()
class PROJECTPORT_API UPCommonPopupWidget : public UPPopupWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UFUNCTION()
	void UpdatePopup();

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextTitle;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextComment;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonConfirm;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UPCommonButton> CommonButtonCancel;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UButton> ButtonBG;

public:
	UFUNCTION()
	void InitCommonPopup(FText TitleText, FText CommentText, bool ShowCancelButton);

	UFUNCTION()
	TSoftObjectPtr<UButton> GetCommonButtonConfirm() { return CommonButtonConfirm->GetButtonBG(); }

	UFUNCTION()
	TSoftObjectPtr<UButton> GetCommonButtonCancel() { return CommonButtonCancel->GetButtonBG(); }

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText TitleText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText CommentText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool ShowCancelButton;
};
