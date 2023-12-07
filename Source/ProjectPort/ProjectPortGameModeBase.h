// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "UI/PUserWidget.h"

#include "ProjectPortGameModeBase.generated.h"

/**
 * Base Gamemode of Project
 */
UCLASS()
class PROJECTPORT_API AProjectPortGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
	virtual void StartPlay() override;

protected:
	// Need to set from blueprint
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSubclassOf<UPUserWidget> MainHUDWidgetClass;

	UPROPERTY()
	TSoftObjectPtr<UPUserWidget> MainHUDWidget;
};
