// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Door/KeyLockedDoor.h"
#include "Inventory/InventoryComponent.h"
#include "Interactable/InteractableInfoComponent.h"
#include "UI/HUD/MainPlayerHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Door/DoorKeyTypeFunctions.h"

void AKeyLockedDoor::BeginPlay()
{
	Super::BeginPlay();

	if (bIsLocked)
	{
		InteractableInfo->SetObjectName(INVTEXT("Locked Door"));
		InteractableInfo->SetInteractionName(INVTEXT("try to unlock"));
	}
}

void AKeyLockedDoor::Interact_Implementation(AActor* InteractingActor)
{
	if (bIsLocked)
	{
		if (auto* Inventory = InteractingActor->GetComponentByClass<UInventoryComponent>())
		{
			const auto& DoorKeys = Inventory->GetDoorKeys();
			for (const auto& Key : DoorKeys)
			{
				if (Key->GetType() == UnlockedBy)
				{
					bIsLocked = false;

					InteractableInfo->SetObjectName(INVTEXT("Door"));
					InteractableInfo->SetInteractionName(INVTEXT("open"));

					break;
				}
			}
		}

		if (bIsLocked) // still locked - didn't find key
		{
			auto* World = GetWorld();
			check(World);

			auto* PC = UGameplayStatics::GetPlayerController(World, 0);
			check(PC);

			auto* HUD = Cast<AMainPlayerHUD>(PC->GetHUD());
			check(HUD);
			
			FText Message = FText::Format(INVTEXT("You need {0} key"), UDoorKeyTypeFunctions::DoorKeyTypeToFText(UnlockedBy));
			HUD->ShowPlayerMessage(Message);
		}
	}
	else
	{
		ChangeState();
	}
}
