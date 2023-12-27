// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/UserWidgets/InteractableInfoWidget.h"
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

	UPROPERTY(EditAnywhere)
	TSubclassOf<UInteractableInfoWidget> InteractableInfoWidgetClass;
	UPROPERTY()
	UInteractableInfoWidget* InteractableInfoWidget;
};

