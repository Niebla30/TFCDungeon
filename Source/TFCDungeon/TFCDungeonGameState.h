// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#pragma once

#include "CoreMinimal.h"
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
	ATFCDungeonGameState();
	virtual void BeginPlay() override;
	
};
