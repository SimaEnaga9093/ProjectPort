// Fill out your copyright notice in the Description page of Project Settings.


#include "PJobIcon.h"

#include "Components/SizeBox.h"
#include "Components/Image.h"

void UPJobIcon::NativePreConstruct()
{
	Super::NativePreConstruct();

	SizeBoxBG->SetWidthOverride(WidthHeightOverride.X);
	SizeBoxBG->SetHeightOverride(WidthHeightOverride.Y);

	UpdateJobType(JobType);
}

void UPJobIcon::UpdateJobType(EContentCharacterJob NewJob)
{
	JobType = NewJob;

	ImageIcon->SetBrushFromTexture(IconJobImages[JobType].LoadSynchronous());
}
