// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Door/Door.h"
#include "Door/DoorKeyType.h"
#include "KeyLockedDoor.generated.h"

class USoundBase;

UCLASS()
class RESI_API AKeyLockedDoor : public ADoor
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void Interact_Implementation(AActor* InteractingActor) override;

protected:
	UFUNCTION()
	void OnRep_IsLocked();

	UPROPERTY(EditAnywhere, ReplicatedUsing = OnRep_IsLocked)
	bool bIsLocked;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	EDoorKeyType UnlockedBy;

	UPROPERTY(EditDefaultsOnly)
	USoundBase* UnlockingSound;
};
