// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.


#include "GameModes/ResiGameMode.h"
#include "Characters/Player/MainPlayerController.h"
#include "UI/HUD/MainPlayerHUD.h"

void AResiGameMode::InitGameState()
{
	Super::InitGameState();

	DefaultPawnClass = nullptr;
	PlayerControllerClass = AMainPlayerController::StaticClass();
	//HUDClass = AMainPlayerHUD::StaticClass();
}
