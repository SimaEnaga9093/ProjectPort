// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PUserWidget.h"
#include "../../Data/PContentCharacterInfo.h"

#include "PJobIcon.generated.h"

class USizeBox;
class UImage;
class UTexture2D;

/**
 * Module Job Icon with EContentCharacterJob
 */
UCLASS()
class PROJECTPORT_API UPJobIcon : public UPUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativePreConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<USizeBox> SizeBoxBG;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TSoftObjectPtr<UImage> ImageIcon;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TMap<EContentCharacterJob, TSoftObjectPtr<UTexture2D>> IconJobImages;

public:
	UFUNCTION()
	void UpdateJobType(EContentCharacterJob NewJob);

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector2D WidthHeightOverride;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EContentCharacterJob JobType;
};
