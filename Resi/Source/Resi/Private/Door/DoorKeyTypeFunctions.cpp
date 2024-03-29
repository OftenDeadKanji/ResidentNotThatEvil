// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Door/DoorKeyTypeFunctions.h"

FText UDoorKeyTypeFunctions::DoorKeyTypeToFText(EDoorKeyType Type)
{
#define LOCTEXT_NAMESPACE "InteractionObjectsNames"
	switch (Type)
	{
		default:
		case EDoorKeyType::Universal:
			return LOCTEXT("UniversalKey", "Universal");
		case EDoorKeyType::Brass:
			return LOCTEXT("BrassKey","Brass");
		case EDoorKeyType::Iron:
			return LOCTEXT("IronKey","Iron");
	}
#undef LOCTEXT_NAMESPACE
}
