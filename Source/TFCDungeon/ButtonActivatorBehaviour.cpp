// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "ButtonActivatorBehaviour.h"

void UButtonActivatorBehaviour::OnEnter()
{
	UE_LOG(LogTemp, Warning, TEXT("BUTTONACTIVATOR ENTER"));
}

void UButtonActivatorBehaviour::OnExit()
{
	UE_LOG(LogTemp, Warning, TEXT("BUTTONACTIVATOR EXIT"));
}