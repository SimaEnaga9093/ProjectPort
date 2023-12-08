// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "ProjectPortGameModeBase.generated.h"

class UPHUDWidget;

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
	TSubclassOf<UPHUDWidget> MainHUDWidgetClass;

	UPROPERTY()
	TSoftObjectPtr<UPHUDWidget> MainHUDWidget;

	UPROPERTY()
	TArray<TSoftObjectPtr<UPHUDWidget>> HUDWidgetHistory;

	UFUNCTION()
	void OnBackPressed();

public:
	UFUNCTION()
	UPHUDWidget* OpenHUDWidget(const FString& HUDName, int ZOrder = 0);
};
