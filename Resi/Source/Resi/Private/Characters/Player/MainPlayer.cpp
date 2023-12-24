// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.


#include "Characters/Player/MainPlayer.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"

AMainPlayer::AMainPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(RootComponent);
}

void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMainPlayer::MoveRight(float Value)
{
	if (auto* MovementComp = GetMovementComponent())
	{
		FVector Movement = GetActorRightVector() * Value;
		MovementComp->AddInputVector(Movement);
	}
}

void AMainPlayer::MoveForward(float Value)
{
	if (auto* MovementComp = GetMovementComponent())
	{
		FVector Movement = GetActorForwardVector() * Value;
		MovementComp->AddInputVector(Movement);
	}
}

void AMainPlayer::LookUp(float Value)
{
	if (MainCamera)
	{
		FRotator Rotation = MainCamera->GetRelativeRotation();
		
		Rotation.Pitch = FMath::Clamp(Rotation.Pitch + Value, CameraLookUpRange.X, CameraLookUpRange.Y);

		MainCamera->SetRelativeRotation(Rotation);
	}
}

void AMainPlayer::Turn(float Value)
{
	FRotator Rotation = GetActorRotation();

	Rotation.Yaw += Value;

	SetActorRotation(Rotation);

}

void AMainPlayer::Interact()
{

}

void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

