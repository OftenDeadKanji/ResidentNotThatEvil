// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Interactable/InteractableInfoComponent.h"

UInteractableInfoComponent::UInteractableInfoComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInteractableInfoComponent::SetObjectName(const FText& Name)
{
	ObjectName = Name;
}

void UInteractableInfoComponent::SetInteractionName(const FText & Name)
{
	InteractionName = Name;
}

const FText& UInteractableInfoComponent::GetObjectName() const
{
	return ObjectName;
}

const FText& UInteractableInfoComponent::GetInteractionName() const
{
	return InteractionName;
}
