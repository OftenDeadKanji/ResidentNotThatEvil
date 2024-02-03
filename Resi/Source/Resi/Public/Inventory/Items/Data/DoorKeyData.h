// Copyright (c) 2024, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Inventory/Items/Data/InventoryItemData.h"
#include "Door/DoorKeyType.h"
#include "DoorKeyData.generated.h"

UCLASS()
class RESI_API UDoorKeyData : public UInventoryItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EDoorKeyType Type;
};
