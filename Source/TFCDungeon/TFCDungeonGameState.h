// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "TFCDungeonGameState.generated.h"

/**
 * 
 */
UCLASS()
class TFCDUNGEON_API ATFCDungeonGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ATFCDungeonGameState();
	virtual void BeginPlay() override;
	
};
