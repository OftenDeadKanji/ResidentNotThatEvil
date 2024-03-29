// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Door/KeyLockedDoor.h"
#include "Inventory/InventoryComponent.h"
#include "Interactable/InteractableInfoComponent.h"
#include "UI/HUD/MainPlayerHUD.h"
#include "Kismet/GameplayStatics.h"
#include "Door/DoorKeyTypeFunctions.h"
#include <Net/UnrealNetwork.h>

void AKeyLockedDoor::BeginPlay()
{
	Super::BeginPlay();

	OnRep_IsLocked();
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
					OnRep_IsLocked();

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

void AKeyLockedDoor::OnRep_IsLocked()
{
	if (bIsLocked)
	{
		InteractableInfo->SetObjectName(NSLOCTEXT("InteractionObjectsNames", "LockedDoor", "Locked Door"));
		InteractableInfo->SetInteractionName(NSLOCTEXT("InteractionActionName", "TryToUnlock", "try to unlock"));
	}
	else
	{
		InteractableInfo->SetObjectName(NSLOCTEXT("InteractionObjectsNames", "Door", "Door"));
		InteractableInfo->SetInteractionName(NSLOCTEXT("InteractionActionsNames", "Open", "open"));
	}
}

void AKeyLockedDoor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AKeyLockedDoor, bIsLocked);
}