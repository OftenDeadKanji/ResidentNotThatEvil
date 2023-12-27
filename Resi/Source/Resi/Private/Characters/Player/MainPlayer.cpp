// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.


#include "Characters/Player/MainPlayer.h"
#include "Characters/Player/MainPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Interactable/Interactable.h"
#include "Interactable/InteractableInfoComponent.h"
#include "UI/HUD/MainPlayerHUD.h"
#include "Inventory/InventoryComponent.h"

AMainPlayer::AMainPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	MainCamera->SetupAttachment(RootComponent);

	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
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
	if (InteractableInRange)
	{
		IInteractable::Execute_Interact(InteractableInRange, this);
	}
}

void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto* World = GetWorld();

	auto* PC = Cast<AMainPlayerController>(GetController());
	check(PC);

	auto* HUD = Cast<AMainPlayerHUD>(PC->GetHUD());
	check(HUD);

	FHitResult Hit;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(this);

	FVector Start = MainCamera->GetComponentLocation();
	FVector End = Start + 200.0f * MainCamera->GetForwardVector();

	if (World->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_Camera, CollisionParams))
	{
		GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Yellow, TEXT("Hit"));
		if (Hit.GetActor()->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
		{
			GEngine->AddOnScreenDebugMessage(0, 0.1f, FColor::Yellow, TEXT("Hit with interactable"));
			InteractableInRange = Hit.GetActor();
			if (auto* InteractableInfoComponent = Hit.GetActor()->GetComponentByClass<UInteractableInfoComponent>())
			{
				HUD->ShowInteractableInfo(InteractableInfoComponent);
			}
			else
			{
				HUD->HideInteractableInfo();
			}
		}
		else
		{
			HUD->HideInteractableInfo();
		}
	}
	else
	{
		InteractableInRange = nullptr;
		HUD->HideInteractableInfo();
	}
}
