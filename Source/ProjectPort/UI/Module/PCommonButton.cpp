// Fill out your copyright notice in the Description page of Project Settings.


#include "PCommonButton.h"
#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Fonts/SlateFontInfo.h"

void UPCommonButton::NativePreConstruct()
{
	Super::NativePreConstruct();

	SizeBoxBG->SetWidthOverride(WidthHeightOverride.X);
	SizeBoxBG->SetHeightOverride(WidthHeightOverride.Y);

	TextMain->SetText(MainText);

	FSlateFontInfo TextMainFont = TextMain->GetFont();
	TextMainFont.Size = TextSize;
	TextMain->SetFont(TextMainFont);
}
