// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "TFCDungeonEnums.h"
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
	

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TSubclassOf<AActor> EndPointClass;

	UPROPERTY(BlueprintReadOnly)
	bool LevelCompleted;

	UPROPERTY(Editanywhere, BlueprintReadWrite, Replicated)
	int LevelTime;

	UPROPERTY(Editanywhere, BlueprintReadWrite, Replicated)
	int LevelDiamonds;

	UPROPERTY(Editanywhere, BlueprintReadWrite, Replicated)
	bool PlayerDying;
};
