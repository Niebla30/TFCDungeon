// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "EndPointBehaviour.h"
#include "TFCDungeonGameState.h"
#include "EngineMinimal.h"
#include "TFCDungeonGameMode.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UEndPointBehaviour::UEndPointBehaviour()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

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

	State = EEndPointState::Free;

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
	if ((OtherActor->GetClass() == BoyPawn.Get() && OwnerCharacter == ECharacter::FireBoy) ||
		(OtherActor->GetClass() == GirlPawn.Get() && OwnerCharacter == ECharacter::WaterGirl))
	{
		State = EEndPointState::Busy;

		if (OnEndPointChangeState.IsBound())
			OnEndPointChangeState.Broadcast(OwnerCharacter, State);
	}
	
	return (State == EEndPointState::Busy);
	
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, "Ha entrado la chica");
}

bool UEndPointBehaviour::OnLeaveEndPoint(AActor* OtherActor)
{

	if ((OtherActor->GetClass() == BoyPawn.Get() && OwnerCharacter == ECharacter::FireBoy) ||
		(OtherActor->GetClass() == GirlPawn.Get() && OwnerCharacter == ECharacter::WaterGirl))
	{
		State = EEndPointState::Free;

		if (OnEndPointChangeState.IsBound())
			OnEndPointChangeState.Broadcast(OwnerCharacter, State);
	}

	return (State == EEndPointState::Free);
	
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Yellow, "Ha salido la chica");
}