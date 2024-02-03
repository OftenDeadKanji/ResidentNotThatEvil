// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Inventory/Items/InventoryItemPickUp.h"
#include "Inventory/Items/InventoryItem.h"
#include "Inventory/Items/Data/InventoryItemData.h"
#include "Inventory/InventoryComponent.h"
#include "Interactable/InteractableInfoComponent.h"
#include "Characters/Player/MainPlayer.h"

AInventoryItemPickUp::AInventoryItemPickUp()
{
	InteractableInfo = CreateDefaultSubobject<UInteractableInfoComponent>(TEXT("InteractableInfo"));

	bReplicates = true;
}

UInventoryItemData* AInventoryItemPickUp::GetConfigData() const
{
	return ConfigData;
}

void AInventoryItemPickUp::SetConfigData(UInventoryItemData* Data, bool bCallInit)
{
	ConfigData = Data;

	if (bCallInit)
	{
		Item->Init(this, ConfigData);
	}
}

void AInventoryItemPickUp::SetItem(UInventoryItem* NewItem, UInventoryItemData* Data)
{
	Item = NewItem;
	ConfigData = Data;

	InteractableInfo->SetObjectName(ConfigData->Name);
	InteractableInfo->SetInteractionName(ConfigData->PickUpInteractionName);
}

void AInventoryItemPickUp::BeginPlay()
{
	Super::BeginPlay();

	if (Item == nullptr)
	{
		Item = NewObject<UInventoryItem>(this, ConfigData->ItemClass);
	}
	
	Item->Init(this, ConfigData);
	GetStaticMeshComponent()->SetStaticMesh(Item->GetStaticMesh());
	//InteractableInfo->SetObjectName(FText::Format(NSLOCTEXT("InteractionObjectsNames", "ADoorKey", "{0} Door Key"), UDoorKeyTypeFunctions::DoorKeyTypeToFText(InventoryData->Type)));
	//InteractableInfo->SetInteractionName(NSLOCTEXT("InteractionActionsNames", "PickUp", "pick up"));
}

void AInventoryItemPickUp::Interact_Implementation(AActor* InteractingActor)
{
	if (auto* Player = Cast<AMainPlayer>(InteractingActor))
	{
		if (auto* Inventory = InteractingActor->GetComponentByClass<UInventoryComponent>())
		{
			BeforePickUp.Broadcast(Player);

			Inventory->AddItem(Item);
			Destroy();

			AfterPickUp.Broadcast(Player);
		}
	}
}

//void AInventoryItemPickUp::SERVER_Pickup_Implementation(AMainPlayer* Player)
//{
//	GetWorld()->DestroyActor(this);
//}

void AInventoryItemPickUp::ManualInit()
{
	if (Item == nullptr)
	{
		Item = NewObject<UInventoryItem>(this, ConfigData->ItemClass);
	}

	Item->Init(this, ConfigData);

	GetStaticMeshComponent()->SetStaticMesh(Item->GetStaticMesh());
}
