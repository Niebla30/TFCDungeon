// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "ActivatorActor.h"
#include "ButtonActivatorActor.generated.h"

/**
 *
 */
UCLASS()
class TFCDUNGEON_API AButtonActivatorActor : public AActivatorActor
{
	GENERATED_BODY()

public:
	void OnEnter() override;
	void OnExit() override;
	void OnActivableAnimationFinished() override;
};
