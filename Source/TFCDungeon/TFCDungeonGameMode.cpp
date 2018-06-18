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

void ATFCDungeonGameMode::BeginPlay()
{
	Super::BeginPlay();

	auto player = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	player->GetPawn()->Destroy();
	player->UnPossess();

	ACharacter* character = nullptr;
	switch (Cast<UTFCDungeonGameInstance>(GetWorld()->GetGameInstance())->GetOwningCharacter())
	{
	case ECharacter::Char_FireBoy:
		if (BoyPawn != NULL)
			character = GetWorld()->SpawnActor<ACharacter>(BoyPawn, FVector(1602, -1545, 1232), FRotator(0, 0, 0));
		break;
	case ECharacter::Char_WaterGirl:
		if (GirlPawn != NULL)
			character = GetWorld()->SpawnActor<ACharacter>(GirlPawn, FVector(1602, -1545, 1232), FRotator(0, 0, 0));
		break;
	default:
		break;
	}
	player->Possess(character);
}
