// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainPlayer.generated.h"

class UCameraComponent;
class IInteractable;


UCLASS(Blueprintable)
class RESI_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AMainPlayer();

protected:
	virtual void BeginPlay() override;

public:
	void MoveRight(float Value);
	void MoveForward(float Value);
	void LookUp(float Value);
	void Turn(float Value);

	void Interact();

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UCameraComponent* MainCamera;

	UPROPERTY(EditAnywhere)
	FVector2f CameraLookUpRange;

	UPROPERTY(VisibleAnywhere)
	AActor* InteractableInRange;
};
