// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "TFCDungeonGameState.h"
#include "TFCDungeonGameInstance.h"
#include "TFCDungeonSaveGame.h"
#include "Kismet/GameplayStatics.h"

ATFCDungeonGameState::ATFCDungeonGameState()
{
	BusyEndPoints[0] = EEndPointState::Free;
	BusyEndPoints[1] = EEndPointState::Free;

	LevelCompleted = false;
}

void ATFCDungeonGameState::BeginPlay()
{
	Super::BeginPlay();
}

void ATFCDungeonGameState::EndPointChangeStateResponse(ECharacter OwnerCharacter, EEndPointState State)
{

	if (LevelCompleted)
		return;

	BusyEndPoints[OwnerCharacter == ECharacter::FireBoy] = State;

	if ( BusyEndPoints[0] == EEndPointState::Busy && BusyEndPoints[1] == EEndPointState::Busy )
	{

		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, "NIVEL COMPLETADO");

		if (this->HasAuthority())
		{
			LevelCompleted = true;
			UTFCDungeonGameInstance *GI = Cast<UTFCDungeonGameInstance>(UGameplayStatics::GetGameInstance(this));
			if (GI != nullptr)
			{
				// Unblock next level
				GI->LevelsInfo[GI->CurrentLevelId + 1].Blocked = false;
				// Save Game

				UTFCDungeonSaveGame *SGI = Cast<UTFCDungeonSaveGame>(UGameplayStatics::CreateSaveGameObject(UTFCDungeonSaveGame::StaticClass()));
				SGI->LevelsInfo = GI->LevelsInfo;
				UGameplayStatics::SaveGameToSlot(SGI, "Default", 0);

				GI->CppChangeLevel("Transition");				
			}
		}
	}
}

void ATFCDungeonGameState::PlayerDeath()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Yellow, "JUGADOR MUERTO");

	if (this->HasAuthority())
	{
		UTFCDungeonGameInstance *GI = Cast<UTFCDungeonGameInstance>(UGameplayStatics::GetGameInstance(this));
		if (GI != nullptr)
			GI->CppChangeLevel("Transition");
	}
}