// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "ActivatorActor.h"
#include "LeverActivatorActor.generated.h"

/**
 * 
 */
UCLASS()
class TFCDUNGEON_API ALeverActivatorActor : public AActivatorActor
{
	GENERATED_BODY()

public:
	void OnEnter() override;
	void OnExit() override;
};
