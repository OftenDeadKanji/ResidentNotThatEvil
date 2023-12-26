// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.


#include "Door/Door.h"
#include "Components/SkeletalMeshComponent.h"
#include "Interactable/InteractableInfoComponent.h"

ADoor::ADoor()
{
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent >(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

	Mesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));

	InteractableInfo = CreateDefaultSubobject<UInteractableInfoComponent>(TEXT("InteractableInfo"));
	InteractableInfo->SetObjectName(INVTEXT("Door"));
	InteractableInfo->SetInteractionName(INVTEXT("open"));
}

void ADoor::Interact_Implementation(AActor* InteractingActor)
{
	ChangeState();
}

void ADoor::ChangeState()
{
	if (CurrentState == DoorState::Opening || CurrentState == DoorState::Closing)
	{
		return;
	}

	if (CurrentState == DoorState::Closed)
	{
		CurrentState = DoorState::Opening;

		OnDoorStartOpening.Broadcast();
	}
	else // Open
	{
		CurrentState = DoorState::Closing;

		OnDoorStartClosing.Broadcast();
	}
}

bool ADoor::IsClosed() const
{
	return CurrentState == DoorState::Closed;
}

bool ADoor::IsClosing() const
{
	return CurrentState == DoorState::Closing;
}

bool ADoor::IsOpen() const
{
	return CurrentState == DoorState::Open;
}

bool ADoor::IsOpening() const
{
	return CurrentState == DoorState::Opening;
}

void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADoor::OnClosingAnimationFinished()
{
	CurrentState = DoorState::Closed;

	OnDoorFinishClosing.Broadcast();
}

void ADoor::OnOpeningAnimationFinished()
{
	CurrentState = DoorState::Open;

	OnDoorFinishOpening.Broadcast();
}

