// Copyright (c) 2023, Mateusz Ch�opek. All rights reserved.


#include "ResiGameMode.h"
#include "Characters/Player/MainPlayerController.h"

void AResiGameMode::InitGameState()
{
	Super::InitGameState();

	DefaultPawnClass = nullptr;
	PlayerControllerClass = AMainPlayerController::StaticClass();
}
