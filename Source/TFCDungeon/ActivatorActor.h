// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TFCDungeonEnums.h"
#include "ActivatorActor.generated.h"

UCLASS(Abstract)
class TFCDUNGEON_API AActivatorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActivatorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class UBoxComponent* Collider;

	UMaterialInterface* ParentMaterial;
	UMaterialInstanceDynamic* RuneMatInst;

	// Set material to no glowing, and color according to Activator element.
	void SetColor(bool bGlow = false);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Config")
		class AActivableActor* Target;
	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Config")
		EElement Element;
	UPROPERTY(BlueprintReadOnly, Category = "Config")
		bool bEnabled;

	virtual void PostEditChangeProperty(FPropertyChangedEvent& e) override;

	UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnEndOverlap(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable, Category = "GamePlay|Activator")
		virtual void OnEnter() PURE_VIRTUAL(UActivatorBehaviour::OnEnter, );
	UFUNCTION(BlueprintCallable, Category = "GamePlay|Activator")
		virtual void OnExit() PURE_VIRTUAL(UActivatorBehaviour::OnExit, );
	
	virtual void OnActivableAnimationFinished();
};
