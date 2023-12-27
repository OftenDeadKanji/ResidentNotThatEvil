// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Door/Door.h"
#include "Door/DoorKeyType.h"
#include "KeyLockedDoor.generated.h"


UCLASS()
class RESI_API AKeyLockedDoor : public ADoor
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Interact_Implementation(AActor* InteractingActor) override;

protected:
	UPROPERTY(EditAnywhere)
	bool bIsLocked;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	EDoorKeyType UnlockedBy;
};
