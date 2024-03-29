// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Door/DoorKey.h"
#include "Inventory/InventoryComponent.h"
#include "Door/DoorKeyTypeFunctions.h"
#include "Interactable/InteractableInfoComponent.h"

ADoorKey::ADoorKey()
{
	InteractableInfo = CreateDefaultSubobject<UInteractableInfoComponent>(TEXT("InteractableInfo"));
	InteractableInfo->SetObjectName(FText::Format(NSLOCTEXT("InteractionObjectsNames", "ADoorKey", "{0} Door Key"), UDoorKeyTypeFunctions::DoorKeyTypeToFText(Type)));
	InteractableInfo->SetInteractionName(NSLOCTEXT("InteractionActionsNames", "PickUp", "pick up"));

	bReplicates = true;
}

EDoorKeyType ADoorKey::GetType() const
{
	return Type;
}

void ADoorKey::Interact_Implementation(AActor* InteractingActor)
{
	if (auto* Inventory = InteractingActor->GetComponentByClass<UInventoryComponent>())
	{
		Inventory->AddDoorKey(this);

		Destroy();
	}
}
