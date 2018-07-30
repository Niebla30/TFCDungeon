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
	this->Blocked = true;
	this->Seconds = 0;
}

