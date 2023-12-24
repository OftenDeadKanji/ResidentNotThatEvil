// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.


#include "Characters/Player/MainPlayerController.h"
#include "Characters/Player/MainPlayer.h"

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis(TEXT("MainPlayer_MoveRight"), this, &AMainPlayerController::CallMoveRight);
	InputComponent->BindAxis(TEXT("MainPlayer_MoveForward"), this, &AMainPlayerController::CallMoveForward);
	InputComponent->BindAxis(TEXT("MainPlayer_LookUp"), this, &AMainPlayerController::CallLookUp);
	InputComponent->BindAxis(TEXT("MainPlayer_Turn"), this, &AMainPlayerController::CallTurn);

	InputComponent->BindAction(TEXT("MainPlayer_Interact"), IE_Pressed, this, &AMainPlayerController::CallInteract);
}

void AMainPlayerController::SetPlayerPawnToPosses(AMainPlayer* PlayerPawn)
{
	if (PlayerPawn)
	{
		MainPlayer = PlayerPawn;
		Possess(MainPlayer);
	}
}

void AMainPlayerController::CallMoveRight(float Value)
{
	if (MainPlayer)
	{
		MainPlayer->MoveRight(Value);
	}
}

void AMainPlayerController::CallMoveForward(float Value)
{
	if (MainPlayer)
	{
		MainPlayer->MoveForward(Value);
	}
}

void AMainPlayerController::CallLookUp(float Value)
{
	if (MainPlayer)
	{
		MainPlayer->LookUp(Value);
	}
}

void AMainPlayerController::CallTurn(float Value)
{
	if (MainPlayer)
	{
		MainPlayer->Turn(Value);
	}
}

void AMainPlayerController::CallInteract()
{
	if (MainPlayer)
	{
		MainPlayer->Interact();
	}
}
