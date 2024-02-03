// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "InventoryItem.generated.h"

class UInventoryItemData;
class AInventoryItemPickUp;

UCLASS()
class RESI_API UInventoryItem : public UObject
{
	GENERATED_BODY()
	
public:
	virtual void Init(AInventoryItemPickUp* OwnerPickUp);
	virtual void Init(AInventoryItemPickUp* OwnerPickUp, UInventoryItemData* ItemData);

	const FText& GetName() const;
	const FText& GetDescription() const;
	UStaticMesh* GetStaticMesh() const;
	bool GetIsStackable() const;
	int GetCount();

	void SetupPickUp(AInventoryItemPickUp* PickUp);

protected:
	UFUNCTION()
	void OnBeforePickUp(AMainPlayer* Player);

	virtual void OnBeforePickUpInternal(AMainPlayer* Player);


	UInventoryItemData* Data;

	// NOT from DataAsset
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Count;
};
