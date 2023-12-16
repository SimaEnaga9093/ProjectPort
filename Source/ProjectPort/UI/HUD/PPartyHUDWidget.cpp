// Fill out your copyright notice in the Description page of Project Settings.


#include "PPartyHUDWidget.h"


UPPartyHUDWidget::UPPartyHUDWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	HUDNameText = FText::FromString("Party");

}

void UPPartyHUDWidget::OnOpen()
{
	Super::OnOpen();

}
