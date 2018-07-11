// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActivableActor.generated.h"

UCLASS()
class TFCDUNGEON_API AActivableActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActivableActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Custom")
	bool bAutoActivation;

	virtual void Play();
	virtual void Loop();
	virtual void Pause();
	virtual void Reverse();
};
