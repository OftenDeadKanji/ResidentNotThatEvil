// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door/DoorState.h"
#include "Interactable/Interactable.h"
#include "Door.generated.h"

class USceneComponent;
class USkeletalMeshComponent;
class UInteractableInfoComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorStartClosing);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorFinishClosing);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorStartOpening);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorFinishOpening);

UCLASS(Blueprintable)
class RESI_API ADoor : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	ADoor();

	virtual void Interact_Implementation(AActor* InteractingActor) override;

	UFUNCTION(BlueprintCallable)
	void ChangeState();

	UFUNCTION(BlueprintCallable)
	bool IsClosed() const;

	UFUNCTION(BlueprintCallable)
	bool IsClosing() const;

	UFUNCTION(BlueprintCallable)
	bool IsOpen() const;

	UFUNCTION(BlueprintCallable)
	bool IsOpening() const;

	UPROPERTY(BlueprintAssignable)
	FDoorStartClosing OnDoorStartClosing;

	UPROPERTY(BlueprintAssignable)
	FDoorFinishClosing OnDoorFinishClosing;

	UPROPERTY(BlueprintAssignable)
	FDoorStartOpening OnDoorStartOpening;

	UPROPERTY(BlueprintAssignable)
	FDoorFinishOpening OnDoorFinishOpening;

	void OnClosingAnimationFinished();
	void OnOpeningAnimationFinished();
protected:
	virtual void BeginPlay() override;

	UFUNCTION(Server, Reliable)
	void SERVER_ChangeState();
	void SERVER_ChangeState_Implementation();

	UFUNCTION()
	void OnRep_CurrentState();

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USkeletalMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Replicated)
	UInteractableInfoComponent* InteractableInfo;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, ReplicatedUsing = OnRep_CurrentState)
	EDoorState CurrentState;
};
