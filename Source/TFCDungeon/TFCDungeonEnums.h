#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ECharacter : uint8
{
	Char_FireBoy UMETA(DisplayName = "FireBoy"),
	Char_WaterGirl UMETA(DisplayName = "WaterGirl")
};

UENUM(BlueprintType)
enum class EEndPointState : uint8
{
	State_Busy UMETA(DisplayName = "Busy"),
	State_Free UMETA(DisplayName = "Free")
};