// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "PQuestBattleShowdowns.generated.h"

UENUM(BlueprintType)
enum class EQuestBattleCategory : uint8
{
	E_Showdowns = 0 UMETA(DisplayName = "Showdowns"),
	E_Abyss = 1 UMETA(DisplayName = "Abyss"),
};

/**
 * Data for quest - battle - showdowns
 */
USTRUCT(BlueprintType)
struct PROJECTPORT_API FPQuestBattleShowdowns : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText TitleName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EQuestBattleCategory Category;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Desc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UTexture2D> BannerImage;
};
