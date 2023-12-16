// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "PContentCharacterInfo.generated.h"

UENUM(BlueprintType)
enum class EContentCharacterJob : uint8
{
	E_Tanker = 0 UMETA(DisplayName = "Tanker"),
	E_Melee = 1 UMETA(DisplayName = "Melee"),
	E_Range = 1 UMETA(DisplayName = "Range"),
	E_Healer = 1 UMETA(DisplayName = "Healer"),
};

/**
 * Data for content - character - info
 */
USTRUCT(BlueprintType)
struct PROJECTPORT_API FPContentCharacterInfo
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EContentCharacterJob Job;
};

USTRUCT(BlueprintType)
struct PROJECTPORT_API FPContentCharacterInfoDataArray
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FPContentCharacterInfo> DataArray;
};
