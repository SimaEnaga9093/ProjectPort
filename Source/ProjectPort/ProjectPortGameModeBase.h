// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "ProjectPortGameModeBase.generated.h"

class UPHUDWidget;
class UPTopBarWidget;
class UPPopupWidget;
class UPToastMessageWidget;

/**
 * Base Gamemode of Project
 */
UCLASS()
class PROJECTPORT_API AProjectPortGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void StartPlay() override;

protected:
	// Need to set from blueprint
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSubclassOf<UPHUDWidget> MainHUDWidgetClass;
	UPROPERTY()
	TSoftObjectPtr<UPHUDWidget> MainHUDWidget;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TSubclassOf<UPTopBarWidget> TopBarWidgetClass;
	UPROPERTY()
	TSoftObjectPtr<UPTopBarWidget> TopBarWidget;

	UPROPERTY()
	TArray<TSoftObjectPtr<UPHUDWidget>> HUDWidgetHistory;

	UPROPERTY()
	TArray<TSoftObjectPtr<UPPopupWidget>> PopupWidgetList;

	UPROPERTY()
	TSoftObjectPtr<UPToastMessageWidget> CachedToastMessageWidget;
	UPROPERTY()
	TArray<FText> ToastMessageTextQueue;

public:
	UFUNCTION()
	void OnBackPressed();

	UFUNCTION()
	TSoftObjectPtr<UPTopBarWidget> GetTopBarWidget() { return TopBarWidget; }

	UFUNCTION()
	UPHUDWidget* OpenHUDWidget(const FString& HUDName, int ZOrder = 0);

	UFUNCTION()
	UPPopupWidget* OpenPopupWidget(const FString& PopupName);

	UFUNCTION()
	void ClosePopup(UPPopupWidget* TargetPopup);

	UFUNCTION()
	void OpenToastMessageWidget(FText ShownMessage);

	UFUNCTION()
	void CloaseToastMessageWidget();

};
