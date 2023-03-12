// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SlashCharacter.generated.h"

class USpringArmComponent;
class	UCameraComponent;
class AItem;

UCLASS()
class RPG2_API ASlashCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:

	virtual void BeginPlay() override;
	void MoveForward(float value);
	void MoveRight(float value);
	void Turn(float value);
	void LookUp(float value);

	void EKeyPressed();
private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	AItem* OverlappingItem;
public:
	FORCEINLINE void SetOverlappingItem(AItem* Item) { OverlappingItem = Item; }
	FORCEINLINE AItem* SetOverlappingItem() { return OverlappingItem; }
};
