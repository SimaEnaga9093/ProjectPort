// Fill out your copyright notice in the Description page of Project Settings.


#include "PCommonButton.h"

#include "Components/SizeBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
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

void UPCommonButton::NativeConstruct()
{
	Super::NativeConstruct();

	if (ButtonBG)
	{
		ButtonBG->OnClicked.AddDynamic(this, &UPCommonButton::OnButtoBGClicked);
	}
}

void UPCommonButton::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if (ActivateInputDelay)
	{
		InputDelayTimer += InDeltaTime;
		if (InputDelayTimer > InputDelaySec)
		{
			ActivateInputDelay = false;
			InputDelayTimer = 0.0f;

			ButtonBG->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

void UPCommonButton::OnButtoBGClicked()
{
	if (InputDelaySec > 0.0f)
	{
		ButtonBG->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		ActivateInputDelay = true;
	}
}