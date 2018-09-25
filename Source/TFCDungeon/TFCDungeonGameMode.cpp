// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "TFCDungeonGameMode.h"
#include "TFCDungeonCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "TFCDungeonEnums.h"
#include "TFCDungeonGameState.h"
#include "TFCDungeonGameInstance.h"
#include "UObject/ConstructorHelpers.h"

ATFCDungeonGameMode::ATFCDungeonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/FireBoy/BP_FireBoy_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		BoyPawn = PlayerPawnBPClass.Class;
	}
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnGirlBPClass(TEXT("/Game/Characters/WaterGirl/BP_WaterGirl_Character"));
	if (PlayerPawnGirlBPClass.Class != NULL)
	{
		GirlPawn = PlayerPawnGirlBPClass.Class;
	}

}

void ATFCDungeonGameMode::PostLogin(APlayerController * NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (NewPlayer->GetPawn() != nullptr) {
		NewPlayer->GetPawn()->Destroy();
		NewPlayer->UnPossess();
	}

	ACharacter* character = nullptr;
	TSubclassOf<APawn> pawn;

	ECharacter Selected = Cast<UTFCDungeonGameInstance>(GetWorld()->GetGameInstance())->SelectedCharacter;
	
	switch (NumPlayers)
	{
	case 1:
		if (Selected == ECharacter::FireBoy)
		{
			pawn = BoyPawn;
			Cast<ATFCDungeonGameState>(GetWorld()->GetGameState())->Player1_type = ECharacter::FireBoy;
			Cast<ATFCDungeonGameState>(GetWorld()->GetGameState())->Player2_type = ECharacter::WaterGirl;

		}
		else if (Selected == ECharacter::WaterGirl)
		{
			pawn = GirlPawn;
			Cast<ATFCDungeonGameState>(GetWorld()->GetGameState())->Player2_type = ECharacter::FireBoy;
			Cast<ATFCDungeonGameState>(GetWorld()->GetGameState())->Player1_type = ECharacter::WaterGirl;
		}
		break;
	case 2:
		if (Selected == ECharacter::FireBoy)
		{
			pawn = GirlPawn;
		}
		else if (Selected == ECharacter::WaterGirl)
		{
			pawn = BoyPawn;
		}
		break;
	default:
		break;
	}
	FTransform SpawnTransform = GetPlayerStart();
	character = GetWorld()->SpawnActor<ACharacter>(pawn, SpawnTransform.GetLocation(), SpawnTransform.GetRotation().Rotator());
	NewPlayer->Possess(character);
}

void ATFCDungeonGameMode::PostSeamlessTravel()
{
	Super::PostSeamlessTravel();
}

void ATFCDungeonGameMode::HandleSeamlessTravelPlayer(AController*& C)
{
	Super::HandleSeamlessTravelPlayer(C);
}

void ATFCDungeonGameMode::InitSeamlessTravelPlayer(AController* NewController)
{
	Super::InitSeamlessTravelPlayer(NewController);

	static int nPlayers = 1;

	APlayerController* NewPlayer = Cast<APlayerController>(NewController);

	if (NewPlayer->GetPawn() != nullptr) {
		NewPlayer->GetPawn()->Destroy();
		NewPlayer->UnPossess();
	}

	if (NewPlayer->GetPawn() != nullptr) {
		NewPlayer->GetPawn()->Destroy();
		NewPlayer->UnPossess();
	}

	ACharacter* character = nullptr;
	TSubclassOf<APawn> pawn;

	ECharacter Selected = Cast<UTFCDungeonGameInstance>(GetWorld()->GetGameInstance())->SelectedCharacter;

	switch (nPlayers)
	{
	case 1:
		if (Selected == ECharacter::FireBoy)
		{
			pawn = BoyPawn;
			Cast<ATFCDungeonGameState>(GetWorld()->GetGameState())->Player1_type = ECharacter::FireBoy;
			Cast<ATFCDungeonGameState>(GetWorld()->GetGameState())->Player2_type = ECharacter::WaterGirl;

		}
		else if (Selected == ECharacter::WaterGirl)
		{
			pawn = GirlPawn;
			Cast<ATFCDungeonGameState>(GetWorld()->GetGameState())->Player2_type = ECharacter::FireBoy;
			Cast<ATFCDungeonGameState>(GetWorld()->GetGameState())->Player1_type = ECharacter::WaterGirl;
		}
		break;
	case 2:
		if (Selected == ECharacter::FireBoy)
		{
			pawn = GirlPawn;
		}
		else if (Selected == ECharacter::WaterGirl)
		{
			pawn = BoyPawn;
		}
		break;
	default:
		break;
	}
	FTransform SpawnTransform = GetPlayerStart();
	character = GetWorld()->SpawnActor<ACharacter>(pawn, SpawnTransform.GetLocation(), SpawnTransform.GetRotation().Rotator());
	NewPlayer->Possess(character);

	nPlayers++;

	if (nPlayers == 3)
		nPlayers = 1;
}


FTransform ATFCDungeonGameMode::GetPlayerStart()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), FoundActors);

	APlayerStart* SpawnPoint = Cast<APlayerStart>(FoundActors[NumPlayers - 1]);
	//ToDo: PlayerStart in order to character, not PlayerController num. 
	return SpawnPoint->GetActorTransform();
}

