// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "UI/HUD/MainPlayerHUD.h"
#include "Blueprint/UserWidget.h"
#include "Interactable/InteractableInfoComponent.h"
#include "Components/TextBlock.h"
#include "Characters/Player/MainPlayerController.h"
#include "Characters/Player/MainPlayer.h"

AMainPlayerHUD::AMainPlayerHUD()
{
	InteractableInfoWidgetClass = nullptr;
	InteractableInfoWidget = nullptr;

	PlayerMessageWidgetClass = nullptr;
	PlayerMessageWidget = nullptr;

	CrosshairWidgetClass = nullptr;
	CrosshairWidget = nullptr;

	InventoryWidgetClass = nullptr;
	InventoryWidget = nullptr;
}

void AMainPlayerHUD::BeginPlay()
{
	Super::BeginPlay();
	
	auto* PC = Cast<AMainPlayerController>(GetOwningPlayerController());
	check(PC);

	auto* Player = Cast<AMainPlayer>(PC->GetPawn());
	check(Player);

	InteractableInfoWidget = CreateWidget<UInteractableInfoWidget>(PC, InteractableInfoWidgetClass);
	InteractableInfoWidget->AddToViewport();
	InteractableInfoWidget->SetVisibility(ESlateVisibility::Collapsed);

	PlayerMessageWidget = CreateWidget<UPlayerMessageWidget>(PC, PlayerMessageWidgetClass);
	PlayerMessageWidget->AddToViewport();
	PlayerMessageWidget->SetVisibility(ESlateVisibility::Collapsed);

	CrosshairWidget = CreateWidget<UCrosshairWidget>(PC, CrosshairWidgetClass);
	CrosshairWidget->AddToViewport();
	CrosshairWidget->SetVisibility(ESlateVisibility::HitTestInvisible);

	InventoryWidget = CreateWidget<UInventoryWidget>(PC, InventoryWidgetClass);
	InventoryWidget->AddToViewport();
	InventoryWidget->SetVisibility(ESlateVisibility::Collapsed);
	InventoryWidget->SetInventory(Player->GetInventory());
}

void AMainPlayerHUD::ShowInteractableInfo(const UInteractableInfoComponent* InteractableInfo)
{
	InteractableInfoWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
	InteractableInfoWidget->SetTexts(InteractableInfo->GetObjectName(), InteractableInfo->GetInteractionName());
}

void AMainPlayerHUD::HideInteractableInfo()
{
	InteractableInfoWidget->SetVisibility(ESlateVisibility::Collapsed);
}

void AMainPlayerHUD::OpenInventory()
{
	InventoryWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
	InventoryWidget->Refresh();
}

void AMainPlayerHUD::CloseInventory()
{
	InventoryWidget->SetVisibility(ESlateVisibility::Collapsed);
}

bool AMainPlayerHUD::IsInventoryOpen()
{
	return InventoryWidget->GetVisibility() == ESlateVisibility::HitTestInvisible;
}

void AMainPlayerHUD::ShowPlayerMessage(const FText& Message)
{
	PlayerMessageWidget->ShowMessage(Message, PlayerMessageDisplayime, PlayerMessageAppearTime, PlayerMessageDisappearTime);
}
