// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "TFCDungeonGameState.h"
#include "Kismet/GameplayStatics.h"

ATFCDungeonGameState::ATFCDungeonGameState()
{
	BusyEndPoints[0] = EEndPointState::State_Free;
	BusyEndPoints[1] = EEndPointState::State_Free;
}

void ATFCDungeonGameState::BeginPlay()
{
	Super::BeginPlay();
}

void ATFCDungeonGameState::EndPointChangeStateResponse(ECharacter OwnerCharacter, EEndPointState State)
{
	BusyEndPoints[OwnerCharacter == ECharacter::Char_FireBoy] = State;

	if ( BusyEndPoints[0] == EEndPointState::State_Busy && BusyEndPoints[1] == EEndPointState::State_Busy )
	{

		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, "NIVEL COMPLETADO");

	}
}