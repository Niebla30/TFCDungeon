// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "ActivatorBehaviour.h"
#include "ButtonActivatorBehaviour.generated.h"

/**
 * 
 */
UCLASS()
class TFCDUNGEON_API UButtonActivatorBehaviour : public UActivatorBehaviour
{
	GENERATED_BODY()

		void OnEnter() override;
};
