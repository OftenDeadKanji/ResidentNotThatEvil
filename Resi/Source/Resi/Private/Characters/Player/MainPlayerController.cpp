// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.


#include "Characters/Player/MainPlayerController.h"
#include "Characters/Player/MainPlayer.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/Player/MainPlayerSpawnManager.h"
#include <Net/UnrealNetwork.h>

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

	InputComponent->BindAxis(TEXT("MainPlayer_MoveRight"), this, &AMainPlayerController::CallMoveRight);
	InputComponent->BindAxis(TEXT("MainPlayer_MoveForward"), this, &AMainPlayerController::CallMoveForward);
	InputComponent->BindAxis(TEXT("MainPlayer_LookUp"), this, &AMainPlayerController::CallLookUp);
	InputComponent->BindAxis(TEXT("MainPlayer_Turn"), this, &AMainPlayerController::CallTurn);

	InputComponent->BindAction(TEXT("MainPlayer_Interact"), IE_Pressed, this, &AMainPlayerController::CallInteract);
}

void AMainPlayerController::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);
	UE_LOG(LogTemp, Warning, TEXT("OnPossess LogFrom Net Mode= %d Authority= %d LocallyControlled = %d"), (int32)(GetNetMode()), (int32)(HasAuthority()), (int32)(IsLocalController()));

	if (auto* PossessedPlayer = Cast<AMainPlayer>(aPawn))
	{
		MainPlayer = PossessedPlayer;
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

void AMainPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AMainPlayerController, MainPlayer);
}