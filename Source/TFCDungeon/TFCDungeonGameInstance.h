// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TFCDungeonEnums.h"
#include "TFCDungeonGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TFCDUNGEON_API UTFCDungeonGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	
	virtual void Init() override;

	UFUNCTION()
		virtual void BeginLoadingScreen(const FString& MapName);
	UFUNCTION()
		virtual void EndLoadingScreen(UWorld* InLoadedWorld);

	UTFCDungeonGameInstance();
	
	UFUNCTION(BlueprintCallable, Category = "GameInfo")
	ECharacter GetOwningCharacter();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameInfo")
	ECharacter SelectedCharacter;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "GameInfo")
	bool bImHost;

	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable, Category = "GameInfo")
	void CppChangeLevel(const FString &LevelName);

};
