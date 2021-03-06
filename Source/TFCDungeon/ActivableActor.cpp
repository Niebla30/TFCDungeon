// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "ActivableActor.h"
#include "ActivatorActor.h"


// Sets default values
AActivableActor::AActivableActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	bAutoActivation = bActivated = bLooping = bOneLoop = false;
	WaitingActivator = nullptr;
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

void AActivableActor::Play(AActivatorActor* Activator, bool bPlayAndReverse)
{
	WaitingActivator = Activator;
	bOneLoop = bPlayAndReverse;

	if (!bActivated)
		AnimateForward();
	else
		AnimateBackward();
	bActivated = !bActivated;
}

void AActivableActor::Loop()
{
	bLooping = true;
	Play(); 
}

void AActivableActor::Pause()
{
	bLooping = false;
	bActivated = !bActivated;

	AnimatePause();
}

void AActivableActor::OnPostAnimate()
{
	if (bLooping || bOneLoop)
		Play(WaitingActivator);
	else
	{
		if (WaitingActivator != nullptr)
			WaitingActivator->OnActivableAnimationFinished();
		WaitingActivator = nullptr;
	}
}
