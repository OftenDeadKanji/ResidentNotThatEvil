// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Inventory/InventoryComponent.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}

void UInventoryComponent::AddDoorKey(ADoorKey* DoorKey)
{
	auto* DoorKeyItem = NewObject<UInventoryItemDoorKey>(this);
	DoorKeyItem->SetDoorKeyData(DoorKey);

	DoorKeys.Add(DoorKeyItem);
}

const TArray<UInventoryItemDoorKey*>& UInventoryComponent::GetDoorKeys() const
{
	return DoorKeys;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

}
