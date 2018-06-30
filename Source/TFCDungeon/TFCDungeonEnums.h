// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ECharacter : uint8
{
	Char_FireBoy = 0	UMETA(DisplayName = "FireBoy"),
	Char_WaterGirl		UMETA(DisplayName = "WaterGirl"),
	Char_MaxCharacters	UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EEndPointState : uint8
{
	State_Busy	UMETA(DisplayName = "Busy"),
	State_Free	UMETA(DisplayName = "Free")
};

UENUM(BlueprintType, meta = (Bitflags))
enum class EElement : uint8
{
	Element_None = 1<<0				UMETA(Hidden),
	Element_Fire = 1<<1				UMETA(DisplayName = "Fire"),
	Element_Water = 1<<2			UMETA(DisplayName = "Water"),
	Element_Plasm = (1<<1) + (1<<2) UMETA(DisplayName = "Plasm"),
	Element_Poison = 1<<3			UMETA(DisplayName = "Poison")
};
ENUM_CLASS_FLAGS(EElement)
