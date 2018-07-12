// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "ButtonActivatorActor.h"
#include "ActivableActor.h"

void AButtonActivatorActor::OnEnter()
{
	bEnabled = false;

	SetGlowingColor();
	Target->Play();
}

// Exit of a button is not relevant.
void AButtonActivatorActor::OnExit()
{
}


