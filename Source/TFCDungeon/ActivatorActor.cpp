// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "ActivatorActor.h"
#include "Components/BoxComponent.h"
#include "ActivableActor.h"
#include "TFCDungeonCharacter.h"


// Sets default values
AActivatorActor::AActivatorActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AActivatorActor::BeginPlay()
{
	Super::BeginPlay();

	bBusy = false;

	//Editor variables checkings.
	if (Target == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("Target is set to None on %s."), *GetName());
		return;
	}
	if (Target->bAutoActivation)
		UE_LOG(LogTemp, Error, TEXT("Target %s is autoactivable so it can't have activator."), *Target->GetName());

	//Collision bindings using a BoxComponent.
	Collider = FindComponentByClass<UBoxComponent>();
	if (Collider != nullptr)
	{
		Collider->OnComponentBeginOverlap.AddDynamic(this, &AActivatorActor::OnBeginOverlap);
		Collider->OnComponentEndOverlap.AddDynamic(this, &AActivatorActor::OnEndOverlap);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No collider component on %s."), *GetName());
	}
}

// Called every frame
void AActivatorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActivatorActor::OnBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (bBusy || !OtherActor || OtherActor == this || !OtherComp)
		return;

	//Ignore event if not a character or hasn't a proper element.
	auto* OtherCharacter = static_cast<ATFCDungeonCharacter*>(OtherActor);
	if (OtherCharacter == nullptr || OtherCharacter->Element != Element)
		return;

	bBusy = true;
	OnEnter();
}

void AActivatorActor::OnEndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (!bBusy || !OtherActor || OtherActor == this || !OtherComp)
		return;

	//Ignore event if not a character or hasn't a proper element.
	auto* OtherCharacter = static_cast<ATFCDungeonCharacter*>(OtherActor);
	if (OtherCharacter == nullptr || OtherCharacter->Element != Element)
		return;

	bBusy = false;
	OnExit();
}

