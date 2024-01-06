// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

class AMainPlayer;

UCLASS()
class RESI_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	virtual void SetupInputComponent() override;

protected:
	virtual void OnPossess(APawn* aPawn) override;

private:
	UFUNCTION()
	void CallMoveRight(float Value);
	UFUNCTION()
	void CallMoveForward(float Value);
	UFUNCTION()
	void CallLookUp(float Value);
	UFUNCTION()
	void CallTurn(float Value);

	UFUNCTION()
	void CallInteract();

	UPROPERTY(Replicated)
	AMainPlayer* MainPlayer;
};
