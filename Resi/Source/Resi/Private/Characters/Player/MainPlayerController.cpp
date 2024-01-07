// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.


#include "Characters/Player/MainPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"

#include "Characters/Player/MainPlayer.h"
#include "Characters/Player/MainPlayerSpawnManager.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (GetLocalRole() == ENetRole::ROLE_Authority)
	{
		if (AActor* FoundActor = UGameplayStatics::GetActorOfClass(GetWorld(), AMainPlayerSpawnManager::StaticClass()))
		{
			auto* Spawner = Cast<AMainPlayerSpawnManager>(FoundActor);
			Spawner->SERVER_SpawnNewPlayer(this);
		}
	}
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (auto* LocalPlayer = Cast<ULocalPlayer>(Player))
	{
		if (auto* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (!Input.IsNull())
			{
				InputSystem->AddMappingContext(Input, 0);
			}
		}
	}

	auto* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(InputMoveForward, ETriggerEvent::Triggered, this, &AMainPlayerController::CallMoveForward);
	EnhancedInputComponent->BindAction(InputMoveRight, ETriggerEvent::Triggered, this, &AMainPlayerController::CallMoveRight);
	EnhancedInputComponent->BindAction(InputLookUp, ETriggerEvent::Triggered, this, &AMainPlayerController::CallLookUp);
	EnhancedInputComponent->BindAction(InputTurn, ETriggerEvent::Triggered, this, &AMainPlayerController::CallTurn);
	EnhancedInputComponent->BindAction(InputInteract, ETriggerEvent::Started, this, &AMainPlayerController::CallInteract);
}

void AMainPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	if (auto* PossessedPlayer = Cast<AMainPlayer>(aPawn))
	{
		PossessedMainPlayer = PossessedPlayer;
	}
}

void AMainPlayerController::CallMoveRight(const FInputActionValue& Value)
{
	if (PossessedMainPlayer)
	{
		float MoveValue = Value.Get<float>();
		PossessedMainPlayer->MoveRight(MoveValue);
	}
}

void AMainPlayerController::CallMoveForward(const FInputActionValue& Value)
{
	if (PossessedMainPlayer)
	{
		float MoveValue = Value.Get<float>();
		PossessedMainPlayer->MoveForward(MoveValue);
	}
}

void AMainPlayerController::CallLookUp(const FInputActionValue& Value)
{
	if (PossessedMainPlayer)
	{
		float LookUpValue = Value.Get<float>();
		PossessedMainPlayer->LookUp(LookUpValue);
	}
}

void AMainPlayerController::CallTurn(const FInputActionValue& Value)
{
	if (PossessedMainPlayer)
	{
		float TurnValue = Value.Get<float>();
		PossessedMainPlayer->Turn(TurnValue);
	}
}

void AMainPlayerController::CallInteract(const FInputActionValue& Value)
{
	if (PossessedMainPlayer)
	{
		float TurnValue = Value.Get<float>();
		PossessedMainPlayer->Interact();
	}
}

void AMainPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMainPlayerController, PossessedMainPlayer);
}