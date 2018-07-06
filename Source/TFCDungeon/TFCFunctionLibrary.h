// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TFCDungeonEnums.h"
#include "TFCFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class TFCDUNGEON_API UTFCFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintPure, meta = (DisplayName = "EElement == EElement",
				CompactNodeTitle = "==", Keywords = "== element compare"),
				Category = "GamePlay|Elements")
		static bool CompareElements(EElement A, EElement B);
	
	
};
