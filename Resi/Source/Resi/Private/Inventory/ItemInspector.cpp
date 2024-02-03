// Copyright (c) 2024, Mateusz Chłopek. All rights reserved.


#include "Inventory/ItemInspector.h"
#include "Inventory/Items/InventoryItem.h"
#include "Inventory/Items/Data/InventoryItemData.h"

AItemInspector::AItemInspector()
{
	PrimaryActorTick.bCanEverTick = true;

	auto* Root = GetRootComponent();

	InspectedItemMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("InspectedItemMeshComponent"));
	InspectedItemMeshComponent->SetupAttachment(Root);

	InspectedItemMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	bReplicates = false;
}

void AItemInspector::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItemInspector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemInspector::StartInspectingItem(UInventoryItem* Item)
{
	InspectedItem = Item;

	InspectedItemMeshComponent->SetStaticMesh(InspectedItem->GetStaticMesh());
}

void AItemInspector::AddPitch(float Value)
{
	auto Rotation = InspectedItemMeshComponent->GetComponentRotation();
	Rotation.Pitch += Value;
	InspectedItemMeshComponent->SetWorldRotation(Rotation);
}

void AItemInspector::AddYaw(float Value)
{
	auto Rotation = InspectedItemMeshComponent->GetComponentRotation();
	Rotation.Yaw += Value;
	InspectedItemMeshComponent->SetWorldRotation(Rotation);
}

void AItemInspector::AddRoll(float Value)
{
	auto Rotation = InspectedItemMeshComponent->GetComponentRotation();
	Rotation.Roll += Value;
	InspectedItemMeshComponent->SetWorldRotation(Rotation);
}

