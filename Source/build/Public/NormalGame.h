// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Engine/TargetPoint.h"
#include "NPC.h"
#include "NormalGame.generated.h"

class ATargetPoints;

UCLASS()
class BUILD_API ANormalGame : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:

	ANormalGame();
	APawn* PlayerPawn;
	AController* ControllerRef;


	UPROPERTY()
	TArray<AActor*> Waypoints;




	UFUNCTION(BlueprintCallable)
	void StartGame();

	UFUNCTION(BlueprintCallable)
	void Change();
};
