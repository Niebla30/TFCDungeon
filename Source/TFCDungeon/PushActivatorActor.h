// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "ButtonActivatorActor.h"
#include "PushActivatorActor.generated.h"

/**
 * 
 */
UCLASS()
class TFCDUNGEON_API APushActivatorActor : public AActivatorActor
{
	GENERATED_BODY()
	
public:
	void OnEnter() override;
	void OnExit() override;
};
