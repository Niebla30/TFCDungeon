// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "ActivatorBehaviour.h"

UActivatorBehaviour::UActivatorBehaviour()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UActivatorBehaviour::BeginPlay()
{
	Super::BeginPlay();
}

void UActivatorBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

