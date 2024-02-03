// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Items/InventoryItem.h"
#include "Items/InventoryItemDoorKey.h"
#include "InventoryComponent.generated.h"

class ADoorKey;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RESI_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

	void AddDoorKey(UInventoryItemDoorKey* DoorKey);
	const TArray<UInventoryItemDoorKey*>& GetAllDoorKeys() const;

	void AddItem(UInventoryItem* Item);
	const TArray<UInventoryItem*>& GetAllItems() const;

protected:
	UPROPERTY()
	TArray<UInventoryItemDoorKey*> DoorKeys;

	UPROPERTY(VisibleAnywhere)
	TArray<UInventoryItem*> Items;
};
