#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ECharacter : uint8
{
	Char_FireBoy = 0 UMETA(DisplayName = "FireBoy"),
	Char_WaterGirl UMETA(DisplayName = "WaterGirl"),
	Char_MaxCharacters
};

UENUM(BlueprintType)
enum class EEndPointState : uint8
{
	State_Busy UMETA(DisplayName = "Busy"),
	State_Free UMETA(DisplayName = "Free")
};