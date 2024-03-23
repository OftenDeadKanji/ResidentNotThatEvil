// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/UserWidgets/InteractableInfoWidget.h"
#include "UI/UserWidgets/PlayerMessageWidget.h"
#include "UI/UserWidgets/CrosshairWidget.h"
#include "UI/UserWidgets/InventoryWidget.h"
#include "MainPlayerHUD.generated.h"

class UInteractableInfoComponent;

class UInteractableInfoWidget;
class UPlayerMessageWidget;
class UCrosshairWidget;
class UInventoryWidget;

UCLASS()
class RESI_API AMainPlayerHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AMainPlayerHUD();
protected:
	virtual void BeginPlay() override;

public:
	void ShowInteractableInfo(const UInteractableInfoComponent* InteractableInfo);
	void HideInteractableInfo();

	void OpenInventory();
	void CloseInventory();
	bool IsInventoryOpen();

	void ShowPlayerMessage(const FText& Message);
protected:
	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UInteractableInfoWidget> InteractableInfoWidgetClass;
	UPROPERTY()
	UInteractableInfoWidget* InteractableInfoWidget;

	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UPlayerMessageWidget> PlayerMessageWidgetClass;
	UPROPERTY()
	UPlayerMessageWidget* PlayerMessageWidget;

	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UCrosshairWidget> CrosshairWidgetClass;
	UPROPERTY()
	UCrosshairWidget* CrosshairWidget;

	UPROPERTY(EditAnywhere, Category = "Widgets")
	TSubclassOf<UInventoryWidget> InventoryWidgetClass;
	UPROPERTY()
	UInventoryWidget* InventoryWidget;

	UPROPERTY(EditAnywhere)
	float PlayerMessageAppearTime = 1.0f;
	UPROPERTY(EditAnywhere)
	float PlayerMessageDisplayime = 3.0f;
	UPROPERTY(EditAnywhere)
	float PlayerMessageDisappearTime = 1.0f;
};

