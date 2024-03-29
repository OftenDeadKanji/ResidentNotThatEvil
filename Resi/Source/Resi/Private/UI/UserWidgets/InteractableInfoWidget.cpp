// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "UI/UserWidgets/InteractableInfoWidget.h"
#include "Components/TextBlock.h"

void UInteractableInfoWidget::SetTexts(const FText& ObjectName, const FText& InteractionName)
{
	InteractableName->SetText(ObjectName);
	InteractionDescription->SetText(FText::Format(NSLOCTEXT("Interaction", "PressE", "Press E to {0}"), InteractionName));
}
