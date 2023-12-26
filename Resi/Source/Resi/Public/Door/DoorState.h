#pragma once

#include "CoreMinimal.h"
#include "DoorState.generated.h"

UENUM(BlueprintType)
enum class DoorState : uint8
{
	Closed,
	Closing,

	Open,
	Opening
};