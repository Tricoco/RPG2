// Fill out your copyright notice in the Description page of Project Settings.


#include "characters/SlshAnimInstance.h"
#include"characters/SlashCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void USlshAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	SlashCharacter = Cast<ASlashCharacter>(TryGetPawnOwner());
	if (SlashCharacter)
	{
		SlashCharacterMovement =SlashCharacter->GetCharacterMovement();
	}
}

void USlshAnimInstance::NativeUpdateAnimation(float DelatTime)
{
	Super::NativeUpdateAnimation(DelatTime);

	if (SlashCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(SlashCharacterMovement->Velocity);
	}
}
