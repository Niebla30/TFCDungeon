// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TFCDungeonGameMode.generated.h"

UCLASS(minimalapi)
class ATFCDungeonGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATFCDungeonGameMode();
	virtual void PostLogin(APlayerController* NewPlayer) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Characters)
		TSubclassOf<APawn> BoyPawn;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Characters)
		TSubclassOf<APawn> GirlPawn;
};



