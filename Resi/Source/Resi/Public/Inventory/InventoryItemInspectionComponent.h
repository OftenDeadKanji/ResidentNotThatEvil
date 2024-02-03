// Copyright (c) 2024, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "InventoryItemInspectionComponent.generated.h"

class UInventoryItemBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RESI_API UInventoryItemInspectionComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UInventoryItemInspectionComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void StartInspection();
protected:
	UInventoryItemBase* InspectedItem;
};
