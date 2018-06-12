// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#include "TFCDungeonGameMode.h"
#include "TFCDungeonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATFCDungeonGameMode::ATFCDungeonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
