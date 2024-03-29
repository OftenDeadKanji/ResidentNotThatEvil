// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "DoorKeyType.h"
#include "Interactable/Interactable.h"
#include "DoorKey.generated.h"

class UInteractableInfoComponent;

UCLASS()
class RESI_API ADoorKey : public AStaticMeshActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	ADoorKey();

	EDoorKeyType GetType() const;

	virtual void Interact_Implementation(AActor* InteractingActor) override;
protected:
	UPROPERTY(VisibleAnywhere)
	UInteractableInfoComponent* InteractableInfo;

	UPROPERTY(EditAnywhere)
	EDoorKeyType Type;
};
