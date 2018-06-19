// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#include "TFCDungeonGameState.h"
#include "Kismet/GameplayStatics.h"

ATFCDungeonGameState::ATFCDungeonGameState()
{
	BusyEndPoints[(int)ECharacter::Char_FireBoy] = EEndPointState::State_Free;
	BusyEndPoints[(int)ECharacter::Char_WaterGirl] = EEndPointState::State_Free;
}

void ATFCDungeonGameState::BeginPlay()
{
	Super::BeginPlay();

	// HABRIA QUE CREAR AQUI EL DELEGATE....NO ESTÁ CLARO QUE LOS OBJETOS ESTÉN CREADOS...

}

void ATFCDungeonGameState::EndPointChangeStateResponse(ECharacter OwnerCharacter, EEndPointState State)
{
	BusyEndPoints[(int)OwnerCharacter] = State;

	if ( BusyEndPoints[(int)ECharacter::Char_FireBoy] == EEndPointState::State_Busy &&
		 BusyEndPoints[(int)ECharacter::Char_WaterGirl] == EEndPointState::State_Busy )
	{

		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, "NIVEL COMPLETADO");

	}
}