// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Interactable/Interactable.h"
#include "InventoryItemPickUp.generated.h"

class UInteractableInfoComponent;
class UInventoryItem;
class UInventoryItemData;
class UInventoryComponent;
class AMainPlayer;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBeforePickup, AMainPlayer*, Player);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAfterPickup, AMainPlayer*, Player);

UCLASS()
class RESI_API AInventoryItemPickUp : public AStaticMeshActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	AInventoryItemPickUp();
	
	FBeforePickup BeforePickUp;
	FAfterPickup AfterPickUp;

	UInventoryItemData* GetConfigData() const;
	void SetConfigData(UInventoryItemData* Data, bool bCallInit = true);

	void SetItem(UInventoryItem* NewItem, UInventoryItemData* Data);
protected:
	virtual void BeginPlay() override;

public:
	virtual void Interact_Implementation(AActor* InteractingActor) override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UInteractableInfoComponent* InteractableInfo{};

	UPROPERTY(EditAnywhere, Category = "Inventory Item")
	UInventoryItemData* ConfigData{};

	UPROPERTY(VisibleAnywhere, Category = "Inventory Item")
	UInventoryItem* Item{};
	
	UPROPERTY(EditAnywhere)
	bool bInitItemWithAssetDataOnBeginPlay{ true };

private:
	UFUNCTION(CallInEditor)
	void ManualInit();
};
