// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "LeverActivatorActor.h"
#include "ActivableActor.h"

void ALeverActivatorActor::OnEnter()
{
	//Once activated, lever is disabled forever (working as an unlocker).
	bEnabled = false;
	SetColor(true); //Glow.
	Target->Play();
}

// Exit of a lever is not relevant.
void ALeverActivatorActor::OnExit()
{
}
