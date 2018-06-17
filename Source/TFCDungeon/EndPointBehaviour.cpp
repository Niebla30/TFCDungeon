// © 2018, Juan Montero Román & Ricardo Guzmán Velasco

#include "EndPointBehaviour.h"
#include "EngineMinimal.h"
#include "TFCDungeonGameMode.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UEndPointBehaviour::UEndPointBehaviour()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEndPointBehaviour::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEndPointBehaviour::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


bool UEndPointBehaviour::OnEnterEndPoint(AActor* OtherActor)
{

	ATFCDungeonGameMode* GMode = (ATFCDungeonGameMode*)UGameplayStatics::GetGameMode(this);
	
	if (OtherActor->GetClass() == GMode->BoyPawn.Get())
		return (OwnerCharacter == ECharacter::Char_FireBoy);

	else if (OtherActor->GetClass() == GMode->GirlPawn.Get())
		return (OwnerCharacter == ECharacter::Char_WaterGirl);
	else
		return false;
	
	// Faltaría una variable en el Game Mode que lleve la cuenta de los que han entrado en End Point
	// Se modifica desde aqui y desde Leave. En el momento en que sumen 2, se acaba el nivel. 
	
	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, "Ha entrado la chica");
}

bool UEndPointBehaviour::OnLeaveEndPoint(AActor* OtherActor)
{

	ATFCDungeonGameMode* GMode = (ATFCDungeonGameMode*)UGameplayStatics::GetGameMode(this);

	if (OtherActor->GetClass() == GMode->BoyPawn.Get())
		return (OwnerCharacter == ECharacter::Char_FireBoy);

	else if (OtherActor->GetClass() == GMode->GirlPawn.Get())
		return (OwnerCharacter == ECharacter::Char_WaterGirl);
	else
		return false;

	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, "Ha entrado la chica");
}