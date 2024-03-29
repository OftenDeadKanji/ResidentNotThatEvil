// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/InventoryItemBase.h"
#include "Door/DoorKeyType.h"
#include "InventoryItemDoorKey.generated.h"

class ADoorKey;

UCLASS()
class RESI_API UInventoryItemDoorKey : public UInventoryItemBase
{
	GENERATED_BODY()
	
public:
	void SetDoorKeyData(ADoorKey* DoorKey);

	bool operator==(const UInventoryItemDoorKey& other);

	EDoorKeyType GetType() const;
protected:
	UPROPERTY(VisibleAnywhere)
	EDoorKeyType Type;
};
