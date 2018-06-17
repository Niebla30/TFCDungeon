// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#include "TFCDungeonGameInstance.h"

UTFCDungeonGameInstance::UTFCDungeonGameInstance()
{
	SelectedCharacter = ECharacter::Char_FireBoy;
	ImHost = false;
}

ECharacter UTFCDungeonGameInstance::GetOwningCharacter()
{
	ECharacter Character = ECharacter::Char_FireBoy;
	switch (SelectedCharacter)
	{
	case ECharacter::Char_FireBoy:
		Character = ImHost ? ECharacter::Char_FireBoy : ECharacter::Char_WaterGirl;
		break;
	case ECharacter::Char_WaterGirl:
		Character = ImHost ? ECharacter::Char_WaterGirl : ECharacter::Char_FireBoy;
		break;
	default:
		break;
	}
	return Character;
}
