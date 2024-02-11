// Fill out your copyright notice in the Description page of Project Settings.


#include "FTA_PlayerSpawningManagementCom.h"
#include "Player/LyraPlayerStart.h"

UFTA_PlayerSpawningManagementCom::UFTA_PlayerSpawningManagementCom(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

AActor* UFTA_PlayerSpawningManagementCom::OnChoosePlayerStart(AController* Player, TArray<ALyraPlayerStart*>& PlayerStarts)
{
	if (PlayerStarts.Num() > 0)
		return PlayerStarts[0];
	return nullptr;
}

void UFTA_PlayerSpawningManagementCom::OnFinishRestartPlayer(AController* Player, const FRotator& StartRotation)
{
}
