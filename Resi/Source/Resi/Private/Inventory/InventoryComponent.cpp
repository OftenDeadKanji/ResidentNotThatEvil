// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Inventory/InventoryComponent.h"
#include "Inventory/Items/InventoryItem.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UInventoryComponent::AddDoorKey(UInventoryItemDoorKey* DoorKey)
{
	DoorKeys.Add(DoorKey);
}

const TArray<UInventoryItemDoorKey*>& UInventoryComponent::GetAllDoorKeys() const
{
	return DoorKeys;
}

void UInventoryComponent::AddItem(UInventoryItem* Item)
{
	Items.Add(Item);
}

const TArray<UInventoryItem*>& UInventoryComponent::GetAllItems() const
{
	return Items;
}

