// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainPlayerSpawnManager.generated.h"

class AMainPlayer;
class AMainPlayerController;
class UBoxComponent;

UCLASS()
class RESI_API AMainPlayerSpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	AMainPlayerSpawnManager();

public:	
	UFUNCTION(Server, Reliable)
	void SERVER_SpawnNewPlayer(AMainPlayerController* Controller);
	void SERVER_SpawnNewPlayer_Implementation(AMainPlayerController* Controller);

protected:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UBoxComponent> SpawnArea;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AMainPlayer> PlayerClassToSpawn;
};
