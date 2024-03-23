// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainPlayer.generated.h"

class UCameraComponent;
class IInteractable;
class UInventoryComponent;
class USceneCaptureComponent2D;
class UTextureRenderTarget2D;

UCLASS(Blueprintable)
class RESI_API AMainPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	AMainPlayer();

	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);

	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);

	UFUNCTION(BlueprintCallable)
	void LookUp(float Value);

	UFUNCTION(BlueprintCallable)
	void Turn(float Value);

	void Interact();

	UInventoryComponent* GetInventory();
protected:	
	UFUNCTION(Server, Reliable)
	void SERVER_Interact(AActor* InteractableActor);
	void SERVER_Interact_Implementation(AActor* InteractableActor);

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UCameraComponent* MainCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UInventoryComponent* Inventory;

	UPROPERTY(EditAnywhere, Category = "Camera Limits")
	FVector2f CameraLookUpRange;

	UPROPERTY(VisibleAnywhere, Category = "Interaction")
	AActor* InteractableInRange{};
};
