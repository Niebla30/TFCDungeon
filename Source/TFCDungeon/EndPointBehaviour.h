// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EndPointBehaviour.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TFCDUNGEON_API UEndPointBehaviour : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEndPointBehaviour();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void OnEnterEndPoint(AActor* OtherActor);
};
