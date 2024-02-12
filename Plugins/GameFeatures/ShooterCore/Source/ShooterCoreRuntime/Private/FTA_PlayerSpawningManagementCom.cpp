// Fill out your copyright notice in the Description page of Project Settings.


#include "FTA_PlayerSpawningManagementCom.h"
#include "Player/LyraPlayerStart.h"
#include "GameModes/LyraGameState.h"
#include "GameFramework/PlayerState.h"

UFTA_PlayerSpawningManagementCom::UFTA_PlayerSpawningManagementCom(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

AActor* UFTA_PlayerSpawningManagementCom::OnChoosePlayerStart(AController* Player, TArray<ALyraPlayerStart*>& PlayerStarts)
{
	ALyraGameState* GameState = GetGameStateChecked<ALyraGameState>();

	// Find the player start which is farest from any players
	ALyraPlayerStart* BestPlayerStart = nullptr;
	double MaxSqrDistance = 0.f;
	ALyraPlayerStart* FallbackPlayerStart = nullptr;
	double FallbackMaxSqrDistance = 0;

	for (ALyraPlayerStart* PlayerStart : PlayerStarts)
	{
		for (APlayerState* PS : GameState->PlayerArray)
		{
			if (PS->IsOnlyASpectator() || PS->GetOwningController() == Player)
			{
				continue;
			}

			if (APawn* Pawn = PS->GetPawn())
			{
				const double SqrDistance = PlayerStart->GetSquaredDistanceTo(Pawn);

				if (PlayerStart->IsClaimed())
				{
					if (FallbackPlayerStart == nullptr || SqrDistance > FallbackMaxSqrDistance)
					{
						FallbackPlayerStart = PlayerStart;
						FallbackMaxSqrDistance = SqrDistance;
					}
				}
				else if (PlayerStart->GetLocationOccupancy(Player) < ELyraPlayerStartLocationOccupancy::Full)
				{
					if (BestPlayerStart == nullptr || SqrDistance > MaxSqrDistance)
					{
						BestPlayerStart = PlayerStart;
						MaxSqrDistance = SqrDistance;
					}
				}
			}
		}
	}

	if (BestPlayerStart)
	{
		return BestPlayerStart;
	}

	return FallbackPlayerStart;
}

void UFTA_PlayerSpawningManagementCom::OnFinishRestartPlayer(AController* Player, const FRotator& StartRotation)
{
}
