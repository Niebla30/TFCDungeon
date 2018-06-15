// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#include "TFCDungeonGameMode.h"
#include "TFCDungeonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATFCDungeonGameMode::ATFCDungeonGameMode()
{
	// set default pawn class to our Blueprinted character
	// Blueprint'/Game/Characters/Mannequin/ThirdPersonCharacter.ThirdPersonCharacter'
	// Blueprint'/Game/Characters/FireBoy/FireBoy_Character.FireBoy_Character'
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/FireBoy/FireBoy_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
