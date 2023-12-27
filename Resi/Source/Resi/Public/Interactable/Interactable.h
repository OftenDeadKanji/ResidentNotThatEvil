// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.generated.h"

class AActor;

UINTERFACE(MinimalAPI, Blueprintable)
class UInteractable : public UInterface
{
	GENERATED_BODY()
};

class RESI_API IInteractable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Interact(AActor* InteractingActor);
};