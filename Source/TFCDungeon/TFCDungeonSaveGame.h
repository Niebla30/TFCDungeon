// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "TFCDungeonLevelInfo.h"
#include "TFCDungeonSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class TFCDUNGEON_API UTFCDungeonSaveGame : public USaveGame
{
	GENERATED_BODY()
	
	
public:

	UTFCDungeonSaveGame();

	// Name of the slot to save game ('Default' alwais)
	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	// Index of the user who is saving game ('0' always)
	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;

	// Best Scores Table
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Basic)
	TArray<FTFCDungeonLevelInfo> LevelsInfo;
	
};
