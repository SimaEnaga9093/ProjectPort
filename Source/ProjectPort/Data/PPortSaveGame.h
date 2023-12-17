// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/SaveGame.h"
#include "PContentCharacterInfo.h"

#include "PPortSaveGame.generated.h"

/**
 * project save game class
 */
UCLASS()
class PROJECTPORT_API UPPortSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPPortSaveGame();

	UPROPERTY(VisibleAnywhere)
	TArray<FPContentCharacterInfo> Characters;
};
