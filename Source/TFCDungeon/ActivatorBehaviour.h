// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TFCDungeonEnums.h"
#include "ActivatorBehaviour.generated.h"

UCLASS( ClassGroup=(Custom), Abstract, meta=(BlueprintSpawnableComponent) )
class TFCDUNGEON_API UActivatorBehaviour : public UActorComponent
{
	GENERATED_BODY()

public:	
	UActivatorBehaviour();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Custom")
	class UActivableBehaviour* Target;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Custom")
		EElement Element;

	UFUNCTION(BlueprintCallable, Category = "GamePlay|Activator")
	virtual void OnEnter() PURE_VIRTUAL(UActivatorBehaviour::OnEnter, );
	UFUNCTION(BlueprintCallable, Category = "GamePlay|Activator")
	virtual void OnExit() PURE_VIRTUAL(UActivatorBehaviour::OnExit, );

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
