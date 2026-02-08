// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "EnemyAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class INTERLINKED_API UEnemyAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData TestVar = 100.0f;
	ATTRIBUTE_ACCESSORS(UEnemyAttributeSet, TestVar)

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override
	{
		Super::PreAttributeChange(Attribute, NewValue);
		if (Attribute == GetTestVarAttribute())
		{
			UAbilitySystemComponent* AbilityComp = GetOwningAbilitySystemComponent();
			const float CurrentVarValue = TestVar.GetBaseValue();

			NewValue = FMath::Clamp<float>(NewValue, 0, 100);

			if (!FMath::IsNearlyEqual(CurrentVarValue, NewValue))
			{
				AbilityComp->ApplyModToAttributeUnsafe(Attribute, EGameplayModOp::Override, NewValue);
			}
		}
	}
};
