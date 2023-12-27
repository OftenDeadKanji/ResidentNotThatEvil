// Copyright (c) 2023, Mateusz Ch³opek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "DoorKeyType.generated.h"

UENUM(BlueprintType)
enum class EDoorKeyType : uint8
{
	Universal,
	Brass,
	Iron
};