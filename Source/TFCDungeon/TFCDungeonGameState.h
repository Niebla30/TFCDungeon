// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

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
	int BusyEndPoints;

	ATFCDungeonGameState();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void EndPointChangeStateResponse(ECharacter OwnerCharacter, EEndPointState State);
	

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	TSubclassOf<AActor> EndPointClass;
};
