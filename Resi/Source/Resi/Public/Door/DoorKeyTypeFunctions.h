// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Door/DoorKeyType.h"
#include "DoorKeyTypeFunctions.generated.h"

/**
 * 
 */
UCLASS()
class RESI_API UDoorKeyTypeFunctions : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static FText DoorKeyTypeToFText(EDoorKeyType Type);
};
