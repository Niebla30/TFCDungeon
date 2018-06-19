// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#pragma once

#include "CoreMinimal.h"
#include "TFCDungeonEnums.h"
#include "Components/ActorComponent.h"
#include "EndPointBehaviour.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEndPointChangeStateSgn, ECharacter, OwnerCharacter, EEndPointState, EndPointState);

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
	bool OnEnterEndPoint(AActor* OtherActor);

	UFUNCTION(BlueprintCallable)
	bool OnLeaveEndPoint(AActor* OtherActor);

	UPROPERTY(Category = Custom, BlueprintReadWrite, EditAnyWhere)
	ECharacter OwnerCharacter;


	UPROPERTY()
		TSubclassOf<APawn> BoyPawn;
	UPROPERTY()
		TSubclassOf<APawn> GirlPawn;
	
	EEndPointState State;

	UPROPERTY(BlueprintAssignable, Category = "Custom")
	FEndPointChangeStateSgn OnEndPointChangeState;
};
