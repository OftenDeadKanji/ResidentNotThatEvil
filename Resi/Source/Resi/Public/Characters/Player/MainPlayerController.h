// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "MainPlayerController.generated.h"

class AMainPlayer;
class UInputAction;

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
	void CallMoveRight(const FInputActionValue& Value);
	UFUNCTION()
	void CallMoveForward(const FInputActionValue& Value);
	UFUNCTION()
	void CallLookUp(const FInputActionValue& Value);
	UFUNCTION()
	void CallTurn(const FInputActionValue& Value);

	UFUNCTION()
	void CallInteract(const FInputActionValue& Value);

	UPROPERTY(Replicated)
	AMainPlayer* PossessedMainPlayer;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> Input;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> InputMoveForward;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> InputMoveRight;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> InputLookUp;
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> InputTurn;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<UInputAction> InputInteract;
};
