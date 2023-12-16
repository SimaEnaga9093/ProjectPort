// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PHUDWidget.h"

#include "PPartyHUDWidget.generated.h"

/**
 * Party HUD
 */
UCLASS()
class PROJECTPORT_API UPPartyHUDWidget : public UPHUDWidget
{
	GENERATED_BODY()

public:
	UPPartyHUDWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void OnOpen() override;
};
