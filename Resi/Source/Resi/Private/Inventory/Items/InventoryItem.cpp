// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Inventory/Items/InventoryItem.h"
#include "Inventory/Items/InventoryItemPickUp.h"
#include "Inventory/Items/Data/InventoryItemData.h"

void UInventoryItem::Init(AInventoryItemPickUp* OwnerPickUp)
{
	OwnerPickUp->SetConfigData(Data);
	OwnerPickUp->BeforePickUp.AddDynamic(this, &UInventoryItem::OnBeforePickUp);
}

void UInventoryItem::Init(AInventoryItemPickUp* OwnerPickUp, UInventoryItemData* ItemData)
{
	OwnerPickUp->BeforePickUp.AddDynamic(this, &UInventoryItem::OnBeforePickUp);

	Data = ItemData;
}

const FText& UInventoryItem::GetName() const
{
	return Data->Name;
}

const FText& UInventoryItem::GetDescription() const
{
	return Data->Description;
}

UStaticMesh* UInventoryItem::GetStaticMesh() const
{
	return Data->StaticMesh;
}

UTexture2D* UInventoryItem::GetIcon() const
{
	return Data->Image;
}

bool UInventoryItem::GetIsStackable() const
{
	return Data->bIsStackable;
}

int UInventoryItem::GetCount()
{
	return Count;
}

void UInventoryItem::SetupPickUp(AInventoryItemPickUp* PickUp)
{
	PickUp->SetItem(this, Data);
}

void UInventoryItem::OnBeforePickUp(AMainPlayer* Player)
{
	OnBeforePickUpInternal(Player);
}

void UInventoryItem::OnBeforePickUpInternal(AMainPlayer* Player)
{}
