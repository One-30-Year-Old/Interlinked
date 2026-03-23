#pragma once
#include "CoreMinimal.h"
#include "Faction.generated.h"

UENUM(BlueprintType)
enum EFaction : uint8
{
	Neutral = 0,
	Player = 1,
	CCG = 2,
	ML = 3,
	TN = 4
};