// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainPlayer.generated.h"

class UCameraComponent;
class IInteractable;
class UInventoryComponent;

UCLASS(Blueprintable)
class RESI_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AMainPlayer();

protected:
	virtual void BeginPlay() override;

public:
	
	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);

	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);

	UFUNCTION(BlueprintCallable)
	void LookUp(float Value);

	UFUNCTION(BlueprintCallable)
	void Turn(float Value);

	void Interact();
protected:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UCameraComponent* MainCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UInventoryComponent* Inventory;

	UPROPERTY(EditAnywhere)
	FVector2f CameraLookUpRange;

	UPROPERTY(VisibleAnywhere)
	AActor* InteractableInRange;
};
