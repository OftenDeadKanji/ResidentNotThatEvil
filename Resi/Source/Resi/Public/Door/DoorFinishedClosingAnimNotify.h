// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "DoorFinishedClosingAnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class RESI_API UDoorFinishedClosingAnimNotify : public UAnimNotify
{
	GENERATED_BODY()
	
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
