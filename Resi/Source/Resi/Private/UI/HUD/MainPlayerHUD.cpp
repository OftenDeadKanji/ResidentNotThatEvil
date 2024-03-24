// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "UI/HUD/MainPlayerHUD.h"
#include "Blueprint/UserWidget.h"
#include "Interactable/InteractableInfoComponent.h"
#include "Components/TextBlock.h"
#include "Characters/Player/MainPlayerController.h"
#include "Characters/Player/MainPlayer.h"
#include "UI/Utilities/WidgetStack/DefaultWidgetStack.h"
#include "UI/Utilities/WidgetStack/HUDWidgetStack.h"

void AMainPlayerHUD::BeginPlay()
{
	Super::BeginPlay();
	
	auto* PC = Cast<AMainPlayerController>(GetOwningPlayerController());
	check(PC);

	auto* Player = Cast<AMainPlayer>(PC->GetPawn());
	check(Player);

	UDefaultWidgetStack* DefaultWidgetStack = NewObject<UDefaultWidgetStack>(this);
	WidgetStacks.Add(DefaultWidgetStack);

	UHUDWidgetStack* HUDWidgetStack = NewObject<UHUDWidgetStack>(this);
	WidgetStacks.Add(HUDWidgetStack);

	InteractableInfoWidget = Cast<UInteractableInfoWidget>(CreateAndPushWidget(InteractableInfoWidgetClass, UHUDWidgetStack::StaticClass()));
	check(InteractableInfoWidget);
	InteractableInfoWidget->SetVisibility(ESlateVisibility::Collapsed);

	PlayerMessageWidget = Cast<UPlayerMessageWidget>(CreateAndPushWidget(PlayerMessageWidgetClass, UHUDWidgetStack::StaticClass()));
	check(PlayerMessageWidget);
	PlayerMessageWidget->SetVisibility(ESlateVisibility::Collapsed);

	CrosshairWidget = Cast<UCrosshairWidget>(CreateAndPushWidget(CrosshairWidgetClass, UHUDWidgetStack::StaticClass()));
	check(CrosshairWidget);
	CrosshairWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
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
	InventoryWidget = Cast<UInventoryWidget>(CreateAndPushWidget(InventoryWidgetClass));
	check(InventoryWidget);
	InventoryWidget->SetVisibility(ESlateVisibility::HitTestInvisible);

	APlayerController* PC = GetOwningPlayerController();
	AMainPlayer* Player = Cast<AMainPlayer>(PC->GetPawn());

	InventoryWidget->SetInventory(Player->GetInventory());
	InventoryWidget->Refresh();
}

void AMainPlayerHUD::CloseInventory()
{
	PopWidget();
	InventoryWidget = nullptr;
}

bool AMainPlayerHUD::IsInventoryOpen()
{
	return InventoryWidget != nullptr;
}

void AMainPlayerHUD::ShowPlayerMessage(const FText& Message)
{
	PlayerMessageWidget->ShowMessage(Message, PlayerMessageDisplayime, PlayerMessageAppearTime, PlayerMessageDisappearTime);
}

UUserWidget* AMainPlayerHUD::CreateAndPushWidget(TSubclassOf<UUserWidget> WidgetClass, TSubclassOf<UWidgetStack> WidgetStackClass)
{
	check(WidgetStackClass);

	for (auto* Stack : WidgetStacks)
	{
		if (Stack->IsA(WidgetStackClass))
		{
			return Stack->CreateAndPushWidget(GetOwningPlayerController(), WidgetClass);
		}
	}

	UWidgetStack* Stack = NewObject<UWidgetStack>(this, WidgetStackClass);
	WidgetStacks.Add(Stack);

	return Stack->CreateAndPushWidget(GetOwningPlayerController(), WidgetClass);
}

void AMainPlayerHUD::PopWidget(TSubclassOf<UWidgetStack> WidgetStackClass)
{
	check(WidgetStackClass);

	for (auto* Stack : WidgetStacks)
	{
		if (Stack->IsA(WidgetStackClass))
		{
			Stack->PopWidget();
			return;
		}
	}
}

UUserWidget* AMainPlayerHUD::GetTopWidget(TSubclassOf<UWidgetStack> WidgetStackClass) const
{
	check(WidgetStackClass);

	for (auto* Stack : WidgetStacks)
	{
		if (Stack->IsA(WidgetStackClass))
		{
			return Stack->GetTopWidget();
		}
	}

	return nullptr;
}
