// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class ECharacter : uint8
{
	FireBoy = 0	UMETA(DisplayName = "FireBoy"),
	WaterGirl		UMETA(DisplayName = "WaterGirl"),
	MaxCharacters	UMETA(Hidden)
};

UENUM(BlueprintType)
enum class EEndPointState : uint8
{
	Busy	UMETA(DisplayName = "Busy"),
	Free	UMETA(DisplayName = "Free")
};

UENUM(BlueprintType)
enum class EElement : uint8
{
	Plasm = 0	UMETA(DisplayName = "Plasm"),
	Fire		UMETA(DisplayName = "Fire"),
	Water		UMETA(DisplayName = "Water"),
	Poison		UMETA(DisplayName = "Poison")
};

//Inline necessary in order to compile, insofar as there is no .cpp for this .h file.
inline bool operator==(EElement &Element, EElement Other) {
	return	static_cast<int>(Other) == static_cast<int>(Element) ||
			static_cast<int>(Other) == 0; // Plasm fits any else element.
}