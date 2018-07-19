// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "TFCDungeonGameInstance.h"
#include "Engine/World.h"
#include "MoviePlayer.h"

UTFCDungeonGameInstance::UTFCDungeonGameInstance()
{
	SelectedCharacter = ECharacter::FireBoy;
	bImHost = false;
}

void UTFCDungeonGameInstance::Init()
{
	Super::Init();

	FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UTFCDungeonGameInstance::BeginLoadingScreen);
	FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UTFCDungeonGameInstance::EndLoadingScreen);
}

void UTFCDungeonGameInstance::BeginLoadingScreen(const FString& InMapName)
{
	if (!IsRunningDedicatedServer())
	{
		FLoadingScreenAttributes LoadingScreen;
		LoadingScreen.bAutoCompleteWhenLoadingCompletes = false;
		LoadingScreen.WidgetLoadingScreen = FLoadingScreenAttributes::NewTestLoadingScreenWidget();

		GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
	}

	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, "Empieza la carga del nivel *************");
}

void UTFCDungeonGameInstance::EndLoadingScreen(UWorld* InLoadedWorld)
{
	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, "************* Termina la carga del nivel");
}

ECharacter UTFCDungeonGameInstance::GetOwningCharacter()
{
	ECharacter Character = ECharacter::FireBoy;
	switch (SelectedCharacter)
	{
	case ECharacter::FireBoy:
		Character = GetWorld()->IsServer() ? ECharacter::FireBoy : ECharacter::WaterGirl;
		break;
	case ECharacter::WaterGirl:
		Character = GetWorld()->IsServer() ? ECharacter::WaterGirl : ECharacter::FireBoy;
		break;
	default:
		break;
	}
	return Character;
}

void UTFCDungeonGameInstance::CppChangeLevel_Implementation(const FString &LevelName)
{

	//GetWorld()->GetAuthGameMode()->bUseSeamlessTravel = true;

	GetWorld()->ServerTravel("/Game/Maps/" + LevelName + "?listen");
}

bool UTFCDungeonGameInstance::CppChangeLevel_Validate(const FString &LevelName)
{
	return true;
}