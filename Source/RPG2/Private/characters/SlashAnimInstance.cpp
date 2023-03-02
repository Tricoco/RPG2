// Fill out your copyright notice in the Description page of Project Settings.


#include "characters/SlashAnimInstance.h"
#include"characters/SlashCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void USlashAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	SlashCharacter = Cast<ASlashCharacter>(TryGetPawnOwner());
	if (SlashCharacter)
	{
		
		SlashCharacterMovement = SlashCharacter->GetCharacterMovement();
	}
}

void USlashAnimInstance::NativeUpdateAnimation(float DelatTime)
{
	Super::NativeUpdateAnimation(DelatTime);

	if (SlashCharacterMovement)
	{
	
		GroundSpeed = UKismetMathLibrary::VSizeXY(SlashCharacterMovement->Velocity);
		UE_LOG(LogTemp, Warning, TEXT("GroundSpeed:%f"), GroundSpeed);
	}
}
