// Copyright (c) 2024, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ItemInspector.generated.h"

class UInventoryItem;
class UStaticMeshComponent;

UCLASS()
class RESI_API AItemInspector : public APawn
{
	GENERATED_BODY()

public:
	AItemInspector();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void StartInspectingItem(UInventoryItem* Item);

	void AddPitch(float Value);
	void AddYaw(float Value);
	void AddRoll(float Value);

protected:
	UInventoryItem* InspectedItem;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* InspectedItemMeshComponent;
};
