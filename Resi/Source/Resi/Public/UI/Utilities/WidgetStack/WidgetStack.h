// Copyright (c) 2024, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WidgetStack.generated.h"

class UUserWidget;
class APlayerController;

UCLASS()
class RESI_API UWidgetStack : public UObject
{
	GENERATED_BODY()
	
public:
	UUserWidget* CreateAndPushWidget(APlayerController* Owner, TSubclassOf<UUserWidget> WidgetClass);
	void PopWidget();

	UUserWidget* GetTopWidget() const;
protected:
	TArray<UUserWidget*> Widgets;
};
