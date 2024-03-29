// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryItemDoorKey.h"
#include "InventoryComponent.generated.h"

class ADoorKey;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RESI_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

	void AddDoorKey(ADoorKey* DoorKey);
	const TArray<UInventoryItemDoorKey*>& GetDoorKeys() const;

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<UInventoryItemDoorKey*> DoorKeys;
};
