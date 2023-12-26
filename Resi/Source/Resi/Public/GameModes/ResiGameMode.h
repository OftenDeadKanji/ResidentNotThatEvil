// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Characters/Player/MainPlayer.h"
#include "ResiGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RESI_API AResiGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void InitGameState() override;

};
