// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "ActivatorActor.h"
#include "SwitchActivatorActor.generated.h"

/**
 * 
 */
UCLASS()
class TFCDUNGEON_API ASwitchActivatorActor : public AActivatorActor
{
	GENERATED_BODY()
	
public:
	void OnEnter() override;
	void OnExit() override;
};
