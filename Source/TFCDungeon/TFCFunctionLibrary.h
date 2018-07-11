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
				CompactNodeTitle = "==", Keywords = "== element compare equals",
				ToolTip = "USE THIS INSTEAD OF ENUM DEFAULT =="), Category = "GamePlay|Elements")
		static bool EqualElements(EElement A, EElement B);
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "EElement != EElement",
			CompactNodeTitle = "!=", Keywords = "!= element compare not equals",
			ToolTip = "USE THIS INSTEAD OF ENUM DEFAULT !="), Category = "GamePlay|Elements")
		static bool NotEqualElements(EElement A, EElement B);
};
