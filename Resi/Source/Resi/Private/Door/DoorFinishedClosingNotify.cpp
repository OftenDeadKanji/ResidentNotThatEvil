// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Door/DoorFinishedClosingNotify.h"
#include "Door/Door.h"

void UDoorFinishedClosingNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (auto* Door = Cast<ADoor>(MeshComp->GetOwner()))
	{
		Door->OnClosingAnimationFinished();
	}
}
