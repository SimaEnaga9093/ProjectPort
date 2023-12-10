// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "../Module/PUserWidget.h"

#include "PQuestBattleInfoWidget.generated.h"

class UTextBlock;
class UImage;

/**
 * Quest-Battle info card Widget
 */
UCLASS()
class PROJECTPORT_API UPQuestBattleInfoWidget : public UPUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextTitle;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UImage> ImageBanner;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UTextBlock> TextDesc;

public:
	void UpdateInfoWidget();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText TitleText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText DescText;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UTexture2D> BannerImage;
};
