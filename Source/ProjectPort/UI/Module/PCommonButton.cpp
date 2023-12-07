// Fill out your copyright notice in the Description page of Project Settings.


#include "PCommonButton.h"

#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Fonts/SlateFontInfo.h"

void UPCommonButton::NativePreConstruct()
{
	Super::NativePreConstruct();

	// Update WidthHeightOverride
	SizeBoxBG->SetWidthOverride(WidthHeightOverride.X);
	SizeBoxBG->SetHeightOverride(WidthHeightOverride.Y);

	// Update MainText
	TextMain->SetText(MainText);

	// Update Font of TextSize
	FSlateFontInfo TextMainFont = TextMain->GetFont();
	TextMainFont.Size = TextSize;
	TextMain->SetFont(TextMainFont);
}
