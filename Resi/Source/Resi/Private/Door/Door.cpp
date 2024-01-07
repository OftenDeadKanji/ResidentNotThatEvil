// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.


#include "Door/Door.h"
#include "Components/SkeletalMeshComponent.h"
#include "Interactable/InteractableInfoComponent.h"
#include <Net/UnrealNetwork.h>

ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent >(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	Mesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));

	InteractableInfo = CreateDefaultSubobject<UInteractableInfoComponent>(TEXT("InteractableInfo"));
	InteractableInfo->SetObjectName(NSLOCTEXT("InteractionObjectsNames", "Door", "Door"));
	InteractableInfo->SetInteractionName(NSLOCTEXT("InteractionActionsNames", "Open", "open"));

	bReplicates = true;
}

void ADoor::Interact_Implementation(AActor* InteractingActor)
{
	ChangeState();
}

void ADoor::ChangeState()
{
	if (CurrentState == EDoorState::Opening || CurrentState == EDoorState::Closing)
	{
		return;
	}

	SERVER_ChangeState();
}

bool ADoor::IsClosed() const
{
	return CurrentState == EDoorState::Closed;
}

bool ADoor::IsClosing() const
{
	return CurrentState == EDoorState::Closing;
}

bool ADoor::IsOpen() const
{
	return CurrentState == EDoorState::Open;
}

bool ADoor::IsOpening() const
{
	return CurrentState == EDoorState::Opening;
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADoor::SERVER_ChangeState_Implementation()
{
	if (CurrentState == EDoorState::Closed)
	{
		CurrentState = EDoorState::Opening;

	}
	else // Open
	{
		CurrentState = EDoorState::Closing;

	}

	OnRep_CurrentState();
}

void ADoor::OnRep_CurrentState()
{
	if (CurrentState == EDoorState::Opening)
	{
		OnDoorStartOpening.Broadcast();
	}
	else if (CurrentState == EDoorState::Closing)
	{
		OnDoorStartClosing.Broadcast();
	}
}

void ADoor::OnClosingAnimationFinished()
{
	CurrentState = EDoorState::Closed;

	OnDoorFinishClosing.Broadcast();
}

void ADoor::OnOpeningAnimationFinished()
{
	CurrentState = EDoorState::Open;

	OnDoorFinishOpening.Broadcast();
}

void ADoor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADoor, CurrentState);
}