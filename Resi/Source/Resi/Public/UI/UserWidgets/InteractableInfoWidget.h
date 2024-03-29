// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractableInfoWidget.generated.h"

class UTextBlock;

UCLASS(Blueprintable)
class RESI_API UInteractableInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetTexts(const FText& ObjectName, const FText& InteractionName);
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* InteractableName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* InteractionDescription;
};
