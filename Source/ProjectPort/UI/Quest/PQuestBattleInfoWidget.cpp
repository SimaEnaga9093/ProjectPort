// Fill out your copyright notice in the Description page of Project Settings.


#include "PQuestBattleInfoWidget.h"

#include "Components/TextBlock.h"
#include "Components/Image.h"

void UPQuestBattleInfoWidget::NativePreConstruct()
{
	Super::NativePreConstruct();

	UpdateInfoWidget();
}

void UPQuestBattleInfoWidget::UpdateInfoWidget()
{
	TextTitle->SetText(TitleText);
	TextDesc->SetText(DescText);

	ImageBanner->SetBrushFromTexture(BannerImage.LoadSynchronous(), true);
}

void UPQuestBattleInfoWidget::InitWidget(FPQuestBattleShowdowns Data)
{
	TitleText = Data.TitleName;
	DescText = Data.Desc;
	BannerImage = Data.BannerImage;

	UpdateInfoWidget();
}
