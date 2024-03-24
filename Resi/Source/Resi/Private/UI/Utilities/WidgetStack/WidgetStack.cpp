// Copyright (c) 2024, Mateusz Chłopek. All rights reserved.


#include "UI/Utilities/WidgetStack/WidgetStack.h"
#include "Blueprint/UserWidget.h"

UUserWidget* UWidgetStack::CreateAndPushWidget(APlayerController* Owner, TSubclassOf<UUserWidget> WidgetClass)
{
	UUserWidget* Widget = CreateWidget(Owner, WidgetClass);

	if (Widget)
	{
		Widget->AddToViewport();
		Widgets.Add(Widget);
	}

	return Widget;
}

void UWidgetStack::PopWidget()
{
	if (Widgets.Num() > 0)
	{
		int LastIndex = Widgets.Num() - 1;

		Widgets[LastIndex]->RemoveFromParent();
		Widgets.RemoveAt(LastIndex);
	}
}

UUserWidget* UWidgetStack::GetTopWidget() const
{
	return Widgets.Num() != 0 ? Widgets[Widgets.Num() - 1] : nullptr;
}
