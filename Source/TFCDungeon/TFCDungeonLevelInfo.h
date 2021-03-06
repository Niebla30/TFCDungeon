// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "TFCDungeonLevelInfo.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FTFCDungeonLevelInfo
{
	GENERATED_USTRUCT_BODY();

	FTFCDungeonLevelInfo();
	FTFCDungeonLevelInfo(const int Id, const FText &ShortName, const FString &FullName, const int MaxDiamonds);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelInfo")
	int LevelId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelInfo")
	FText ShortName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelInfo")
	FString FullName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelInfo")
	bool Blocked;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelInfo")
	int Diamonds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelInfo")
	int MaxDiamonds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelInfo")
	int Seconds;

	static void InitLevelsInfo(TArray<FTFCDungeonLevelInfo> &LevelsArray);
};
