// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#include "ActivatorActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TFCFunctionLibrary.h"
#include "ActivableActor.h"
#include "TFCDungeonCharacter.h"


// Sets default values
AActivatorActor::AActivatorActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bEnabled = true;

	static ConstructorHelpers::FObjectFinder<UMaterialInterface> ActivatorMeshMaterial(TEXT("/Game/MaterialLibrary/M_Rune_Master.M_Rune_Master"));
	if (ActivatorMeshMaterial.Object != NULL)
		ParentMaterial = ActivatorMeshMaterial.Object;
	else
		UE_LOG(LogTemp, Error, TEXT("Couldn't find material M_Rune_Master on %s."), *GetName());
}


// Called when the game starts or when spawned
void AActivatorActor::BeginPlay()
{
	Super::BeginPlay();

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

//Set the base material color when Element is changed on editor.
void AActivatorActor::PostEditChangeProperty(FPropertyChangedEvent & e)
{
	Super::PostEditChangeProperty(e);

	if (e.GetPropertyName() != GET_MEMBER_NAME_CHECKED(AActivatorActor, Element))
		return;

	SetColor();
}

void AActivatorActor::OnBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (!bEnabled || !OtherActor || OtherActor == this || !OtherComp)
		return;

	//Ignore event if not a character or hasn't a proper element.
	auto* OtherCharacter = static_cast<ATFCDungeonCharacter*>(OtherActor);
	if (OtherCharacter == nullptr || OtherCharacter->Element != Element)
		return;

	OnEnter();
}

void AActivatorActor::OnEndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (!bEnabled || !OtherActor || OtherActor == this || !OtherComp)
		return;

	//Ignore event if not a character or hasn't a proper element.
	auto* OtherCharacter = static_cast<ATFCDungeonCharacter*>(OtherActor);
	if (OtherCharacter == nullptr || OtherCharacter->Element != Element)
		return;

	OnExit();
}

void AActivatorActor::OnActivableAnimationFinished()
{
	SetColor();
}

void AActivatorActor::SetColor(bool bGlow)
{
	RuneMatInst = UMaterialInstanceDynamic::Create(ParentMaterial, this);
	RuneMatInst->SetVectorParameterValue("ColorBase", UTFCFunctionLibrary::Conv_ElementToLinearColor(Element));
	if(bGlow)
		RuneMatInst->SetScalarParameterValue("Emissive", 100.f);
	FindComponentByClass<UStaticMeshComponent>()->SetMaterial(0, RuneMatInst);
}