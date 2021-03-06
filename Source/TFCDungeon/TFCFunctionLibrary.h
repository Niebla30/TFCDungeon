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

public:

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Element == Element",
				CompactNodeTitle = "==", Keywords = "== element compare equals",
				ToolTip = "USE THIS INSTEAD OF ENUM DEFAULT =="), Category = "GamePlay|Elements")
		static bool EqualElements(EElement A, EElement B);
	
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Element != Element",
			CompactNodeTitle = "!=", Keywords = "!= element compare not equals",
			ToolTip = "USE THIS INSTEAD OF ENUM DEFAULT !="), Category = "GamePlay|Elements")
		static bool NotEqualElements(EElement A, EElement B);

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Element To LinearColor",
			CompactNodeTitle = "->", BlueprintAutocast),
			Category = "GamePlay|Elements")
		static FLinearColor Conv_ElementToLinearColor(EElement InElement);

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "Change Culture"), Category = "Localization")
		static void ChangeCulture(FString Culture);
};
