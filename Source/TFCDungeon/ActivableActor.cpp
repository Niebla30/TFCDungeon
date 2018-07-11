// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "ActivableActor.h"


// Sets default values
AActivableActor::AActivableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bAutoActivation = false;
}

// Called when the game starts or when spawned
void AActivableActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AActivableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActivableActor::Play()
{
	UE_LOG(LogTemp, Warning, TEXT("play"));
}

void AActivableActor::Loop()
{
	UE_LOG(LogTemp, Warning, TEXT("loop"));
}

void AActivableActor::Pause()
{
	UE_LOG(LogTemp, Warning, TEXT("pause"));
}

void AActivableActor::Reverse()
{
	UE_LOG(LogTemp, Warning, TEXT("reverse"));
}

