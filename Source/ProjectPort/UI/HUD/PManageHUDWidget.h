// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PHUDWidget.h"

#include "PManageHUDWidget.generated.h"

class UTileView;

/**
 * Manage HUD
 */
UCLASS()
class PROJECTPORT_API UPManageHUDWidget : public UPHUDWidget
{
	GENERATED_BODY()

public:
	UPManageHUDWidget(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void OnOpen() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTileView> TileViewEntries;
};
