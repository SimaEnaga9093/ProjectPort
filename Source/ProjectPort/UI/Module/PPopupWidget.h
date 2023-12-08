// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PUserWidget.h"

#include "PPopupWidget.generated.h"

/**
 * Base Popup Widget
 */
UCLASS()
class PROJECTPORT_API UPPopupWidget : public UPUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	virtual void OnOpen();

	UFUNCTION()
	virtual void OnClose();

	UFUNCTION()
	virtual bool HandleCloseAction();

	UFUNCTION()
	virtual void ClosePopup();
};
