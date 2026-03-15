// Fill out your copyright notice in the Description page of Project Settings.


#include "InterlinkedAIController.h"
#include <Perception/AIPerceptionSystem.h>
#include "Faction.h"

void AInterlinkedAIController::SetGenericTeamId(const FGenericTeamId& NewTeamID)
{
	Super::SetGenericTeamId(NewTeamID);
	// Update AI perception system
	UAIPerceptionSystem::GetCurrent(GetWorld())->UpdateListener(*GetAIPerceptionComponent());
}

ETeamAttitude::Type AInterlinkedAIController::GetTeamAttitudeTowards(const AActor& Other) const
{
	const APawn* OtherPawn = Cast<APawn>(&Other);
	if (OtherPawn == nullptr) 
	{
		return ETeamAttitude::Neutral;
	}

	auto CharacterTeamAgent = Cast<IGenericTeamAgentInterface>(&Other);
	class IGenericTeamAgentInterface* ControllerTeamAgent = Cast<IGenericTeamAgentInterface>(OtherPawn->GetController());
	if (CharacterTeamAgent == nullptr && ControllerTeamAgent == nullptr)
	{
		return ETeamAttitude::Neutral;
	}

	FGenericTeamId OtherTeamId = FGenericTeamId();
	if (ControllerTeamAgent != nullptr)
	{
		OtherTeamId = ControllerTeamAgent->GetGenericTeamId();
	}
	else if (CharacterTeamAgent != nullptr)
	{
		OtherTeamId = CharacterTeamAgent->GetGenericTeamId();
	}

	FGenericTeamId myTeamId = GetGenericTeamId();
	if (OtherTeamId == EFaction::Neutral)
	{
		return ETeamAttitude::Neutral;
	}

	if (OtherTeamId == myTeamId)
	{
		return ETeamAttitude::Friendly;
	}

	return ETeamAttitude::Hostile;
}
