// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActivatorBehaviour.generated.h"


UCLASS( ClassGroup=(Custom), abstract, meta=(BlueprintSpawnableComponent) )
class TFCDUNGEON_API UActivatorBehaviour : public UActorComponent
{
	GENERATED_BODY()

public:	
	UActivatorBehaviour();

protected:
	virtual void BeginPlay() override;

public:
	void OnEnter();
	void OnExit();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
