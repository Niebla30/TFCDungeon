// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "TFCDungeonSaveGame.h"


UTFCDungeonSaveGame::UTFCDungeonSaveGame() : SaveSlotName("Default"), UserIndex(0)
{
	FTFCDungeonLevelInfo::InitLevelsInfo(LevelsInfo);
}
