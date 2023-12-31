// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Blueprint/UserWidget.h"

#include "PUserWidget.generated.h"

/**
 * Base Class of Project's UserWidget
 */
UCLASS()
class PROJECTPORT_API UPUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPUserWidget(const FObjectInitializer& ObjectInitializer);

	UFUNCTION()
	AProjectPortGameModeBase* GetPortGameMode();
};
