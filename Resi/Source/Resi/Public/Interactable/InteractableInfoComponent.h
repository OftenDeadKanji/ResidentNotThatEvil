// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractableInfoComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RESI_API UInteractableInfoComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInteractableInfoComponent();

	void SetObjectName(const FText& Name);
	void SetInteractionName(const FText& Name);

	const FText& GetObjectName() const;
	const FText& GetInteractionName() const;
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText ObjectName;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText InteractionName;
};
