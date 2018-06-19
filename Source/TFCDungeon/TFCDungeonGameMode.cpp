// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#include "TFCDungeonGameMode.h"
#include "TFCDungeonCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "Engine/World.h"
#include "TFCDungeonEnums.h"
#include "TFCDungeonGameInstance.h"
#include "UObject/ConstructorHelpers.h"

ATFCDungeonGameMode::ATFCDungeonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/FireBoy/FireBoy_Character"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		BoyPawn = PlayerPawnBPClass.Class;
	}
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnGirlBPClass(TEXT("/Game/Characters/WaterGirl/WaterGirl_Character"));
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
		if (Selected == ECharacter::Char_FireBoy)
			pawn = BoyPawn;
		else if (Selected == ECharacter::Char_WaterGirl)
			pawn = GirlPawn;
		break;
	case 2:
		if (Selected == ECharacter::Char_FireBoy)
			pawn = GirlPawn;
		else if (Selected == ECharacter::Char_WaterGirl)
			pawn = BoyPawn;
		break;
	default:
		break;
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

