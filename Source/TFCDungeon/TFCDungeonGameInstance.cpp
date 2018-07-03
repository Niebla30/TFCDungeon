// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "TFCDungeonGameInstance.h"
#include "Engine/World.h"

UTFCDungeonGameInstance::UTFCDungeonGameInstance()
{
	SelectedCharacter = ECharacter::FireBoy;
	bImHost = false;
}

ECharacter UTFCDungeonGameInstance::GetOwningCharacter()
{
	ECharacter Character = ECharacter::FireBoy;
	switch (SelectedCharacter)
	{
	case ECharacter::FireBoy:
		Character = GetWorld()->IsServer() ? ECharacter::FireBoy : ECharacter::WaterGirl;
		break;
	case ECharacter::WaterGirl:
		Character = GetWorld()->IsServer() ? ECharacter::WaterGirl : ECharacter::FireBoy;
		break;
	default:
		break;
	}
	return Character;
}

void UTFCDungeonGameInstance::CppChangeLevel_Implementation()
{

	//GetWorld()->GetAuthGameMode()->bUseSeamlessTravel = true;

	GetWorld()->ServerTravel("/Game/Maps/Level_02?listen");
}

bool UTFCDungeonGameInstance::CppChangeLevel_Validate()
{
	return true;
}