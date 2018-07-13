// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "ButtonActivatorActor.h"
#include "ActivableActor.h"

void AButtonActivatorActor::OnEnter()
{
	bEnabled = false;

	SetColor(true); //Glow.
	Target->Play(this, true); //Play & Reverse.
}

// Exit of a button is not relevant.
void AButtonActivatorActor::OnExit()
{
}


