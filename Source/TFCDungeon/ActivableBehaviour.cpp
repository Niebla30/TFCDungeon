// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "ActivableBehaviour.h"


// Sets default values for this component's properties
UActivableBehaviour::UActivableBehaviour()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActivableBehaviour::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActivableBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UActivableBehaviour::TurnOn()
{
	UE_LOG(LogTemp, Warning, TEXT("TURN ON"));
}

void UActivableBehaviour::TurnOff()
{
	UE_LOG(LogTemp, Warning, TEXT("TURN ON"));
}

