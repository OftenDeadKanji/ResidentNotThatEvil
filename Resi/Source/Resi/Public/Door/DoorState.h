#pragma once

#include "CoreMinimal.h"
#include "DoorState.generated.h"

UENUM(BlueprintType)
enum class EDoorState : uint8
{
	Closed,
	Closing,

	Open,
	Opening
};