// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "UI/HUD/MainPlayerHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/UserWidgets/InteractableInfoWidget.h"
#include "Interactable/InteractableInfoComponent.h"
#include "Components/TextBlock.h"
#include "Characters/Player/MainPlayerController.h"

AMainPlayerHUD::AMainPlayerHUD()
{
	InteractableInfoWidgetClass = nullptr;
	InteractableInfoWidget = nullptr;

	PlayerMessageWidgetClass = nullptr;
	PlayerMessageWidget = nullptr;
}

void AMainPlayerHUD::BeginPlay()
{
	Super::BeginPlay();
	auto* PC = GetOwningPlayerController();
	auto* PCC = Cast<AMainPlayerController>(PC);

	InteractableInfoWidget = CreateWidget<UInteractableInfoWidget>(PCC, InteractableInfoWidgetClass);
	InteractableInfoWidget->AddToViewport();
	InteractableInfoWidget->SetVisibility(ESlateVisibility::Collapsed);

	PlayerMessageWidget = CreateWidget<UPlayerMessageWidget>(PCC, PlayerMessageWidgetClass);
	PlayerMessageWidget->AddToViewport();

	CrosshairWidget = CreateWidget<UCrosshairWidget>(PCC, CrosshairWidgetClass);
	CrosshairWidget->AddToViewport();
}

void AMainPlayerHUD::ShowInteractableInfo(const UInteractableInfoComponent* InteractableInfo)
{
	InteractableInfoWidget->SetVisibility(ESlateVisibility::Visible);
	InteractableInfoWidget->SetTexts(InteractableInfo->GetObjectName(), InteractableInfo->GetInteractionName());
}

void AMainPlayerHUD::HideInteractableInfo()
{
	InteractableInfoWidget->SetVisibility(ESlateVisibility::Collapsed);
}

void AMainPlayerHUD::ShowPlayerMessage(const FText& Message)
{
	PlayerMessageWidget->ShowMessage(Message, PlayerMessageDisplayime, PlayerMessageAppearTime, PlayerMessageDisappearTime);
}
