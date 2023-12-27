// Copyright (c) 2023, Mateusz Chłopek. All rights reserved.


#include "Door/DoorKeyTypeFunctions.h"

FText UDoorKeyTypeFunctions::DoorKeyTypeToFText(EDoorKeyType Type)
{
	switch (Type)
	{
		default:
		case EDoorKeyType::Universal:
			return INVTEXT("Universal");
		case EDoorKeyType::Brass:
			return INVTEXT("Brass");
		case EDoorKeyType::Iron:
			return INVTEXT("Iron");
	}
}
