// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectPortGameModeBase.h"

#include "UI/Module/PHUDWidget.h"
#include "UI/PTopBarWidget.h"
#include "UI/Module/PPopupWidget.h"
#include "UI/Module/PToastMessageWidget.h"
#include "Kismet/GameplayStatics.h"

void AProjectPortGameModeBase::StartPlay()
{
	Super::StartPlay();

	if (MainHUDWidgetClass)
	{
		MainHUDWidget = CreateWidget<UPHUDWidget>(GetWorld(), MainHUDWidgetClass);
		MainHUDWidget->AddToViewport(0);
	}

	if (TopBarWidgetClass)
	{
		TopBarWidget = CreateWidget<UPTopBarWidget>(GetWorld(), TopBarWidgetClass);
		TopBarWidget->AddToViewport(0);
		TopBarWidget->SetNameText(MainHUDWidget->GetHUDNameText());
	}

	APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
	PC->SetShowMouseCursor(true);
	PC->SetInputMode(FInputModeGameAndUI());
	PC->InputComponent->BindAction("Back", IE_Pressed, this, &AProjectPortGameModeBase::OnBackPressed);
}

void AProjectPortGameModeBase::OnBackPressed()
{
	// Release Message First
	if (CachedToastMessageWidget && CachedToastMessageWidget->IsShowned())
	{
		CloaseToastMessageWidget();
	}
	// Release Popup Second
	else if (!PopupWidgetList.IsEmpty())
	{
		TSoftObjectPtr<UPPopupWidget> LastPopupWidget = PopupWidgetList.Last();
		if (LastPopupWidget)
		{
			ClosePopup(LastPopupWidget.Get());
		}
	}
	// Release HUD Third
	else if (!HUDWidgetHistory.IsEmpty())
	{
		if (!MainHUDWidget->HandleBackAction())
		{
			MainHUDWidget->OnBack();
			MainHUDWidget->RemoveFromParent();

			TSoftObjectPtr<UPHUDWidget> LastHUDWidget = HUDWidgetHistory.Last();
			if (LastHUDWidget)
			{
				HUDWidgetHistory.Remove(LastHUDWidget);

				LastHUDWidget->AddToViewport();
				LastHUDWidget->OnOpen();
				MainHUDWidget = LastHUDWidget;
			}
		}
	}
}

UPHUDWidget* AProjectPortGameModeBase::OpenHUDWidget(const FString& HUDName, int ZOrder)
{
	const FString& Path = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/HUD/" + HUDName + "." + HUDName + "_C'");

	FSoftClassPath HUDClassRef(Path);
	if (UClass* NewHUDClass = HUDClassRef.TryLoadClass<UPHUDWidget>())
	{
		MainHUDWidget->OnClose();
		MainHUDWidget->RemoveFromParent();
		HUDWidgetHistory.Add(MainHUDWidget);

		UPHUDWidget* NewHUDWidget = CreateWidget<UPHUDWidget>(GetWorld(), NewHUDClass);
		NewHUDWidget->AddToViewport(ZOrder);
		NewHUDWidget->OnOpen();
		MainHUDWidget = NewHUDWidget;

		return NewHUDWidget;
	}

	return nullptr;
}

UPPopupWidget* AProjectPortGameModeBase::OpenPopupWidget(const FString& PopupName)
{
	const FString& Path = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/Popup/" + PopupName + "." + PopupName + "_C'");
	
	FSoftClassPath PopupClassRef(Path);
	if (UClass* NewPopupClass = PopupClassRef.TryLoadClass<UPPopupWidget>())
	{
		UPPopupWidget* NewPopupWidget = CreateWidget<UPPopupWidget>(GetWorld(), NewPopupClass);
		NewPopupWidget->AddToViewport(1);
		NewPopupWidget->OnOpen();

		PopupWidgetList.Add(NewPopupWidget);

		return NewPopupWidget;
	}

	return nullptr;
}

void AProjectPortGameModeBase::ClosePopup(UPPopupWidget* TargetPopup)
{
	if (!TargetPopup->HandleCloseAction())
	{
		TargetPopup->OnClose();
		TargetPopup->RemoveFromParent();

		PopupWidgetList.Remove(TargetPopup);
	}
}

void AProjectPortGameModeBase::OpenToastMessageWidget(FText ShownMessage)
{
	if (!CachedToastMessageWidget)
	{
		const FString& Path = TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/Module/WBP_ToastMessage.WBP_ToastMessage_C'");

		FSoftClassPath ToastClassRef(Path);
		if (UClass* NewToastClass = ToastClassRef.TryLoadClass<UPToastMessageWidget>())
			CachedToastMessageWidget = CreateWidget<UPToastMessageWidget>(GetWorld(), NewToastClass);
	}

	if (CachedToastMessageWidget->IsShowned())
	{
		ToastMessageTextQueue.Add(ShownMessage);
	}
	else
	{
		CachedToastMessageWidget->MessageText = ShownMessage;
		CachedToastMessageWidget->OpenToastMessage();

		if (!CachedToastMessageWidget->IsVisible())
			CachedToastMessageWidget->AddToViewport(10);
	}
}

void AProjectPortGameModeBase::CloaseToastMessageWidget()
{
	if (!CachedToastMessageWidget)
		return;

	CachedToastMessageWidget->CloaseToastMessage();

	if (!ToastMessageTextQueue.IsEmpty())
	{
		OpenToastMessageWidget(ToastMessageTextQueue[0]);
		ToastMessageTextQueue.RemoveAt(0);
	}
	else
	{
		CachedToastMessageWidget->RemoveFromParent();
	}
}
