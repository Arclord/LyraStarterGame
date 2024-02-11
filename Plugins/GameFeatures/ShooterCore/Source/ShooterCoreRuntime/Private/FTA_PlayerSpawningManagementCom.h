// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Player/LyraPlayerSpawningManagerComponent.h"
#include "FTA_PlayerSpawningManagementCom.generated.h"

class AActor;
class AController;
class ALyraPlayerStart;
class UObject;

/**
 * 
 */
UCLASS()
class UFTA_PlayerSpawningManagementCom : public ULyraPlayerSpawningManagerComponent
{
	GENERATED_BODY()
	
public:

	UFTA_PlayerSpawningManagementCom(const FObjectInitializer& ObjectInitializer);

	virtual AActor* OnChoosePlayerStart(AController* Player, TArray<ALyraPlayerStart*>& PlayerStarts) override;
	virtual void OnFinishRestartPlayer(AController* Player, const FRotator& StartRotation) override;

};
