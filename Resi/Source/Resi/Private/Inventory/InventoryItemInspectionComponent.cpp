// Copyright (c) 2024, Mateusz Chłopek. All rights reserved.


#include "Inventory/InventoryItemInspectionComponent.h"

UInventoryItemInspectionComponent::UInventoryItemInspectionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UInventoryItemInspectionComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UInventoryItemInspectionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
