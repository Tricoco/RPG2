// Fill out your copyright notice in the Description page of Project Settings.


#include "characters/SlashCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ASlashCharacter::ASlashCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;


	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);


	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArm);


}

void ASlashCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ASlashCharacter::MoveForward(float value)
{
	if (Controller && (value != 0.f))
	{
		//获取控制器方向（摄像头绑定控制器时，就是摄像头方向
		const FRotator ContorlRotation = GetControlRotation();
		//只关心偏航角
		const FRotator YawRotator(0.f, ContorlRotation.Yaw, 0.f);
		//matrix=ymat*pmat*rmat )?
		const FVector direction= FRotationMatrix(YawRotator).GetUnitAxis(EAxis::X);
		//将旋转变换应用于X轴上
		AddMovementInput(direction, value);
	}
}

void ASlashCharacter::MoveRight(float value)
{
	if (Controller && (value != 0.f))
	{

		const FRotator ContorlRotation = GetControlRotation();
		const FRotator YawRotator(0.f, ContorlRotation.Yaw, 0.f);
		const FVector direction = FRotationMatrix(YawRotator).GetUnitAxis(EAxis::Y);
		AddMovementInput(direction, value);
	}
}

void ASlashCharacter::Turn(float value)
{
	if (Controller && (value != 0.f))
	{
		AddControllerYawInput(value);
	}
}

void ASlashCharacter::LookUp(float value)
{
	if (Controller && (value != 0.f))
	{
		AddControllerPitchInput(value);
	}
}


void ASlashCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ASlashCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(FName("MoveForward"), this, &ASlashCharacter::MoveForward);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ASlashCharacter::MoveRight);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &ASlashCharacter::LookUp);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &ASlashCharacter::Turn);
}

