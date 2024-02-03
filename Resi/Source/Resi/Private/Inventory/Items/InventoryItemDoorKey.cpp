// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Inventory/Items/InventoryItemDoorKey.h"
#include "Inventory/Items/Data/DoorKeyData.h"
#include "Characters/Player/MainPlayer.h"
#include "Inventory/InventoryComponent.h"

bool UInventoryItemDoorKey::operator==(const UInventoryItemDoorKey& Other)
{
	return Cast<UDoorKeyData>(Data)->Type == Cast<UDoorKeyData>(Other.Data)->Type;
}

EDoorKeyType UInventoryItemDoorKey::GetType() const
{
	return Cast<UDoorKeyData>(Data)->Type;
}

void UInventoryItemDoorKey::OnBeforePickUpInternal(AMainPlayer* Player)
{
	if (auto* Inventory = Player->GetComponentByClass<UInventoryComponent>())
	{
		Inventory->AddDoorKey(this);
	}
}
