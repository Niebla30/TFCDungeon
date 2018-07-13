// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "PushActivatorActor.h"
#include "ActivableActor.h"

void APushActivatorActor::OnEnter()
{
	SetColor(true); //Glow.
	Target->Loop();
}


void APushActivatorActor::OnExit()
{
	SetColor();
	Target->Pause();
}
