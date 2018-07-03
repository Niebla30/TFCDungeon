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

UENUM(BlueprintType)
enum class EElement : uint8
{
	Element_Fire	UMETA(DisplayName = "Fire"),
	Element_Water	UMETA(DisplayName = "Water"),
	Element_Plasm	UMETA(DisplayName = "Plasm"),
	Element_Poison	UMETA(DisplayName = "Poison")
};
