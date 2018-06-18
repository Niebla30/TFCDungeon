// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#include "TFCDungeonGameMode.h"
#include "TFCDungeonCharacter.h"
#include "Kismet/GameplayStatics.h"
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

	auto StartingPoint = NewPlayer->GetPawn()->GetActorTransform();
	NewPlayer->GetPawn()->Destroy();
	NewPlayer->UnPossess();

	ACharacter* character = nullptr;
	TSubclassOf<APawn> pawn;
	switch (Cast<UTFCDungeonGameInstance>(GetWorld()->GetGameInstance())->GetOwningCharacter())
	{
	case ECharacter::Char_FireBoy:
		if (BoyPawn != NULL)
			pawn = BoyPawn;
		break;
	case ECharacter::Char_WaterGirl:
		if (GirlPawn != NULL)
			pawn = GirlPawn;
		break;
	default:
		break;
	}
	character = GetWorld()->SpawnActor<ACharacter>(pawn, StartingPoint.GetLocation(), FRotator(0, 0, 0));
	NewPlayer->Possess(character);
}
