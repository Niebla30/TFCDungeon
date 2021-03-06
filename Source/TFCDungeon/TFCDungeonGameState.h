// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "TFCDungeonEnums.h"
#include "TFCDungeonLevelInfo.h"
#include "GameFramework/GameState.h"
#include "TFCDungeonGameState.generated.h"

/**
 * 
 */
UCLASS()
class TFCDUNGEON_API ATFCDungeonGameState : public AGameState
{
	GENERATED_BODY()

public:
	EEndPointState BusyEndPoints[2];

	ATFCDungeonGameState();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void EndPointChangeStateResponse(ECharacter OwnerCharacter, EEndPointState State);

	UFUNCTION(BlueprintCallable)
	void PlayerDeath();
	
	UFUNCTION(BlueprintCallable)
	void ResetGame();


	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TSubclassOf<AActor> EndPointClass;

	UPROPERTY(Editanywhere, BlueprintReadOnly, Replicated)
	bool LevelCompleted;

	UPROPERTY(Editanywhere, BlueprintReadWrite, Replicated)
	int LevelTime;

	UPROPERTY(Editanywhere, BlueprintReadWrite, Replicated)
	int LevelDiamonds;

	UPROPERTY(Editanywhere, BlueprintReadWrite, Replicated)
	bool PlayerDying;

	UPROPERTY(Editanywhere, BlueprintReadWrite, Replicated)
	ECharacter Player1_type;

	UPROPERTY(Editanywhere, BlueprintReadWrite, Replicated)
	ECharacter Player2_type;
};
