// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Inventory/InventoryItemDoorKey.h"
#include "Door/DoorKey.h"

void UInventoryItemDoorKey::SetDoorKeyData(ADoorKey* DoorKey)
{
	Type = DoorKey->GetType();
}

bool UInventoryItemDoorKey::operator==(const UInventoryItemDoorKey& Other)
{
	return Type == Other.Type;
}

EDoorKeyType UInventoryItemDoorKey::GetType() const
{
	return Type;
}
