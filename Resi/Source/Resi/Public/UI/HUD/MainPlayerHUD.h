// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/UserWidgets/InteractableInfoWidget.h"
#include "UI/UserWidgets/PlayerMessageWidget.h"
#include "UI/UserWidgets/CrosshairWidget.h"
#include "MainPlayerHUD.generated.h"

class UInteractableInfoComponent;

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

	void ShowPlayerMessage(const FText& Message);
protected:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UInteractableInfoWidget> InteractableInfoWidgetClass;
	UPROPERTY()
	UInteractableInfoWidget* InteractableInfoWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UPlayerMessageWidget> PlayerMessageWidgetClass;
	UPROPERTY()
	UPlayerMessageWidget* PlayerMessageWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UCrosshairWidget> CrosshairWidgetClass;
	UPROPERTY()
	UCrosshairWidget* CrosshairWidget;

	UPROPERTY(EditAnywhere)
	float PlayerMessageAppearTime = 1.0f;
	UPROPERTY(EditAnywhere)
	float PlayerMessageDisplayime = 3.0f;
	UPROPERTY(EditAnywhere)
	float PlayerMessageDisappearTime = 1.0f;
};

