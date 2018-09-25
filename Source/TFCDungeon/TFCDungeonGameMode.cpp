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

	
	ECharacter p1 = Cast<ATFCDungeonGameState>(GetWorld()->GetGameState())->Player1_type;
	ECharacter p2 = Cast<ATFCDungeonGameState>(GetWorld()->GetGameState())->Player2_type;
	
	bool ImHost = Cast<UTFCDungeonGameInstance>(GetWorld()->GetGameInstance())->bSoyHost;

	FString pp;

	if (p1 == ECharacter::FireBoy)
		pp = "P1 = FireBoy, ";
	else if (p1 == ECharacter::WaterGirl)
		pp = "P1 = WaterGirl, ";

	if (p2 == ECharacter::FireBoy)
		pp += "P2 = FireBoy, ";
	else if (p2 == ECharacter::WaterGirl)
		pp += "P2 = WaterGirl, ";

	if (ImHost)
		pp += "HOST, ";
	else
		pp += "NO_HOST, ";

	ECharacter Selected = Cast<UTFCDungeonGameInstance>(GetWorld()->GetGameInstance())->SelectedCharacter;

	if (Selected == ECharacter::FireBoy)
		pp += "Selected = FireBoy, ";
	else if (Selected == ECharacter::WaterGirl)
		pp += "Selected = WaterGirl, ";

	GEngine->AddOnScreenDebugMessage(-1, 300.0f, FColor::Yellow, pp);

	APlayerController* NewPlayer = Cast<APlayerController>(NewController);

	if (NewPlayer->GetPawn() != nullptr) {
		NewPlayer->GetPawn()->Destroy();
		NewPlayer->UnPossess();
	}

	ACharacter* character = nullptr;
	TSubclassOf<APawn> pawn;

	

	
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

	FTransform SpawnTransform = GetPlayerStart();
	character = GetWorld()->SpawnActor<ACharacter>(pawn, SpawnTransform.GetLocation(), SpawnTransform.GetRotation().Rotator());
	NewPlayer->Possess(character);
}


FTransform ATFCDungeonGameMode::GetPlayerStart()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), FoundActors);

	APlayerStart* SpawnPoint = Cast<APlayerStart>(FoundActors[NumPlayers - 1]);
	//ToDo: PlayerStart in order to character, not PlayerController num. 
	return SpawnPoint->GetActorTransform();
}

