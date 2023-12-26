// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"

#include "PContentCharacterInfo.generated.h"

UENUM(BlueprintType)
enum class EContentCharacterJob : uint8
{
	E_None = 0 UMETA(DisplayName = "None"),
	E_Tanker = 1 UMETA(DisplayName = "Tanker"),
	E_Melee = 2 UMETA(DisplayName = "Melee"),
	E_Range = 3 UMETA(DisplayName = "Range"),
	E_Healer = 4 UMETA(DisplayName = "Healer"),
};

UENUM(BlueprintType)
enum class EContentCharacterStat : uint8
{
	E_STR = 0 UMETA(DisplayName = "STR"),
	E_DEX = 1 UMETA(DisplayName = "DEX"),
	E_INT = 2 UMETA(DisplayName = "INT"),
	E_MND = 3 UMETA(DisplayName = "MND"),
};

/**
 * Data for content - character - info
 */
USTRUCT(BlueprintType)
struct PROJECTPORT_API FPContentCharacterInfo : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EContentCharacterJob Job;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<EContentCharacterStat, int> Stats = {
		{ EContentCharacterStat::E_STR, 0 },
		{ EContentCharacterStat::E_DEX, 0 },
		{ EContentCharacterStat::E_INT, 0 },
		{ EContentCharacterStat::E_MND, 0 },
	};

	bool operator==(const FPContentCharacterInfo& A)
	{
		return (A.Name == Name) && (A.Job == Job);
	}
};
