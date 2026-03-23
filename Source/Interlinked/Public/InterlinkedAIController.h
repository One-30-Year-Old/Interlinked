// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "InterlinkedAIController.generated.h"

/**
 * 
 */
UCLASS()
class INTERLINKED_API AInterlinkedAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	void SetGenericTeamId(const FGenericTeamId& NewTeamID) override;

protected:

	virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;
};
