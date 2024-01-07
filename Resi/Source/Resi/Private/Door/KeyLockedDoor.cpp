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
		InteractableInfo->SetObjectName(NSLOCTEXT("InteractionObjectsNames", "LockedDoor", "Locked Door"));
		InteractableInfo->SetInteractionName(NSLOCTEXT("InteractionActionName", "TryToUnlock", "try to unlock"));
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

					InteractableInfo->SetObjectName(NSLOCTEXT("InteractionObjectsNames", "Door", "Door"));
					InteractableInfo->SetInteractionName(NSLOCTEXT("InteractionActionsNames", "Open", "open"));

					UGameplayStatics::PlaySound2D(GetWorld(), UnlockingSound);

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
			
			FText Message = FText::Format(NSLOCTEXT("PlayerMessages", "YouNeedAKey", "You need {0} key"), UDoorKeyTypeFunctions::DoorKeyTypeToFText(UnlockedBy));
			HUD->ShowPlayerMessage(Message);
		}
	}
	else
	{
		ChangeState();
	}
}
