// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#include "TFCDungeonGameState.h"
#include "Kismet/GameplayStatics.h"

ATFCDungeonGameState::ATFCDungeonGameState()
{
	BusyEndPoints = 0;
}

void ATFCDungeonGameState::BeginPlay()
{
	Super::BeginPlay();

	// HABRIA QUE CREAR AQUI EL DELEGATE....NO ESTÁ CLARO QUE LOS OBJETOS ESTÉN CREADOS...

}

void ATFCDungeonGameState::EndPointChangeStateResponse(ECharacter OwnerCharacter, EEndPointState State)
{
	if (State == EEndPointState::State_Busy)
		BusyEndPoints++;
	else
		BusyEndPoints--;

	if (BusyEndPoints == 2)
	{

		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, "NIVEL COMPLETADO");

	}
}