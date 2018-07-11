// © 2018, Juan Montero Román & Ricardo Guzmán Velasco.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActivableActor.generated.h"

UCLASS(Abstract)
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

	virtual void Play() PURE_VIRTUAL(AActivableActor::Play, );
	virtual void Loop() PURE_VIRTUAL(AActivableActor::Loop, );
	virtual void Pause() PURE_VIRTUAL(AActivableActor::Pause, );
	virtual void Reverse() PURE_VIRTUAL(AActivableActor::Reverse, );
	
};
