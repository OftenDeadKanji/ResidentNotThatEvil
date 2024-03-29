// Copyright (c) 2024, Mateusz Chłopek. All rights reserved.


#include "Characters/Player/MainPlayerSpawnManager.h"
#include "Components/BoxComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Characters/Player/MainPlayer.h"
#include "Characters/Player/MainPlayerController.h"

AMainPlayerSpawnManager::AMainPlayerSpawnManager()
{
	PrimaryActorTick.bCanEverTick = false;

	SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnArea"));
	RootComponent = SpawnArea;
}

void AMainPlayerSpawnManager::SERVER_SpawnNewPlayer_Implementation(AMainPlayerController* Controller)
{
	FVector SpawnLocation = UKismetMathLibrary::RandomPointInBoundingBox(SpawnArea->GetComponentLocation(), SpawnArea->GetScaledBoxExtent());

	float GroundZ = SpawnArea->GetComponentLocation().Z - SpawnArea->GetScaledBoxExtent().Z;
	if (auto* Pla = Cast<AMainPlayer>(AMainPlayer::StaticClass()->GetDefaultObject()))
	{
		float PlayerHeight = Pla->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
		SpawnLocation.Z = GroundZ + PlayerHeight;

		auto* SpawnedPlayer = GetWorld()->SpawnActor(PlayerClassToSpawn, &SpawnLocation, &FRotator::ZeroRotator);
		
		SpawnedPlayer->SetOwner(Controller);
		Controller->Possess(Cast<AMainPlayer>(SpawnedPlayer));
	}
}

