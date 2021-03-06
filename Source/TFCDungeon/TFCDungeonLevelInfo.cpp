// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "TFCDungeonLevelInfo.h"

FTFCDungeonLevelInfo::FTFCDungeonLevelInfo()
{
}

FTFCDungeonLevelInfo::FTFCDungeonLevelInfo(const int Id, const FText &ShortName, const FString &FullName, const int MaxDiamonds)
{
	LevelId = Id;

	this->ShortName = ShortName;
	this->FullName = FullName;
	this->MaxDiamonds = MaxDiamonds;
	this->Diamonds = 0;
	this->Blocked = (Id > 0);
	this->Seconds = 0;
}

void FTFCDungeonLevelInfo::InitLevelsInfo(TArray<FTFCDungeonLevelInfo> &LevelsArray)
{
	LevelsArray.Init(FTFCDungeonLevelInfo(), 8);

	//FTFCDungeonLevelInfo aux(1, FText::FromString("Level 01"), "/Game/Maps/Level_01", 3);

	LevelsArray[0] = FTFCDungeonLevelInfo(0, FText::FromString("Level_01"), "/Game/Maps/Level_01", 3);
	LevelsArray[1] = FTFCDungeonLevelInfo(1, FText::FromString("Level_02"), "/Game/Maps/Level_02", 3);
	LevelsArray[2] = FTFCDungeonLevelInfo(2, FText::FromString("Level_03"), "/Game/Maps/Level_03", 3);
	LevelsArray[3] = FTFCDungeonLevelInfo(3, FText::FromString("Level_04"), "/Game/Maps/Level_04", 3);
	LevelsArray[4] = FTFCDungeonLevelInfo(4, FText::FromString("Level_05"), "/Game/Maps/Level_05", 3);
	LevelsArray[5] = FTFCDungeonLevelInfo(5, FText::FromString("Level_06"), "/Game/Maps/Level_06", 3);
	LevelsArray[6] = FTFCDungeonLevelInfo(6, FText::FromString("Level_07"), "/Game/Maps/Level_07", 3);
	LevelsArray[7] = FTFCDungeonLevelInfo(7, FText::FromString("Level_08"), "/Game/Maps/Level_08", 3);
}

