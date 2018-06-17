// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#include "EndPointBehaviour.h"
#include "EngineMinimal.h"


// Sets default values for this component's properties
UEndPointBehaviour::UEndPointBehaviour()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEndPointBehaviour::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEndPointBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UEndPointBehaviour::OnEnterEndPoint(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, OtherActor->GetFName().ToString());
}
