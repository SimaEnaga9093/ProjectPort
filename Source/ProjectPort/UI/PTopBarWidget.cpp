// Fill out your copyright notice in the Description page of Project Settings.


#include "PTopBarWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "../ProjectPortGameModeBase.h"

void UPTopBarWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ButtonBack)
		ButtonBack->OnClicked.AddDynamic(this, &UPTopBarWidget::OnButtonBackClicked);
}

void UPTopBarWidget::NativeDestruct()
{
	Super::NativeDestruct();

	if (ButtonBack)
		ButtonBack->OnClicked.RemoveDynamic(this, &UPTopBarWidget::OnButtonBackClicked);
}

void UPTopBarWidget::OnButtonBackClicked()
{
	GetPortGameMode()->OnBackPressed();
}

void UPTopBarWidget::SetNameText(const FText& Text)
{
	TextName->SetText(Text);
}
