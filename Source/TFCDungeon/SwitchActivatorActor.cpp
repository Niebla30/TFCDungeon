// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "SwitchActivatorActor.h"
#include "ActivableActor.h"

void ASwitchActivatorActor::OnEnter()
{
	SetColor(true); //Glow.
	Target->Play(this);
}

// Exit of a switch is not relevant.
void ASwitchActivatorActor::OnExit()
{
}
