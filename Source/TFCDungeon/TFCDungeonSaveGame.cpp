// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "TFCDungeonSaveGame.h"


UTFCDungeonSaveGame::UTFCDungeonSaveGame() : SaveSlotName("Default"), UserIndex(0)
{
	LevelsInfo.Init(FTFCDungeonLevelInfo(), 8);

	//FTFCDungeonLevelInfo aux(1, FText::FromString("Level 01"), "/Game/Maps/Level_01", 3);

	LevelsInfo[0] = FTFCDungeonLevelInfo(1, FText::FromString("Level 01"), "/Game/Maps/Level_01", 3);
	LevelsInfo[1] = FTFCDungeonLevelInfo(2, FText::FromString("Level 02"), "/Game/Maps/Level_02", 3);
	LevelsInfo[2] = FTFCDungeonLevelInfo(3, FText::FromString("Level 03"), "/Game/Maps/Level_03", 3);
	LevelsInfo[3] = FTFCDungeonLevelInfo(4, FText::FromString("Level 04"), "/Game/Maps/Level_04", 3);
	LevelsInfo[4] = FTFCDungeonLevelInfo(5, FText::FromString("Level 05"), "/Game/Maps/Level_05", 3);
	LevelsInfo[5] = FTFCDungeonLevelInfo(6, FText::FromString("Level 06"), "/Game/Maps/Level_06", 3);
	LevelsInfo[6] = FTFCDungeonLevelInfo(7, FText::FromString("Level 07"), "/Game/Maps/Level_07", 3);
	LevelsInfo[7] = FTFCDungeonLevelInfo(8, FText::FromString("Level 08"), "/Game/Maps/Level_08", 3);

}
