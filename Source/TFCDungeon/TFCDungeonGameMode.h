// � 2018, Juan Montero Rom�n & Ricardo Guzm�n Velasco.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TFCDungeonGameMode.generated.h"

UCLASS(minimalapi)
class ATFCDungeonGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ATFCDungeonGameMode();
	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void PostSeamlessTravel() override;
	virtual void HandleSeamlessTravelPlayer(AController*& C) override;
	virtual void InitSeamlessTravelPlayer(AController* NewController) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Characters)
		TSubclassOf<APawn> BoyPawn;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Characters)
		TSubclassOf<APawn> GirlPawn;

protected:
	FTransform GetPlayerStart();
};



