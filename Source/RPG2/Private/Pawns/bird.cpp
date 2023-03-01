// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

Abird::Abird()
{
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);
	SetRootComponent(Capsule);//equals to(	RootComponent = Capsule;)

	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
	BirdMesh->SetupAttachment(GetRootComponent());
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->TargetArmLength = 300.f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(SpringArm);


	AutoPossessPlayer = EAutoReceiveInput::Player0;
}


void Abird::BeginPlay()
{
	Super::BeginPlay();
}

void Abird::MoveForward(float value)
{
	if (Controller  && (value != 0.f))
	{
		FVector Forward = GetActorForwardVector();
		AddMovementInput(Forward,value);
	}
}

void Abird::Turn(float value)
{
	if (Controller && (value != 0.f))
	{
		AddControllerYawInput(value);
	}
}

void Abird::LookUp(float value)
{
	if (Controller && (value != 0.f))
	{
		AddControllerPitchInput(value);
	}
}

void Abird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void Abird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//与UE编辑器中项目设置 输入 轴映射配合
	PlayerInputComponent->BindAxis(FName("MoveForward"),this,&Abird::MoveForward);
	PlayerInputComponent->BindAxis(FName("LookUp"), this, &Abird::LookUp);
	PlayerInputComponent->BindAxis(FName("Turn"), this, &Abird::Turn);
}

