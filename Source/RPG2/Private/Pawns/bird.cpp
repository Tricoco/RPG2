// Fill out your copyright notice in the Description page of Project Settings.


#include "Pawns/bird.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

Abird::Abird()
{
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetCapsuleHalfHeight(20.f);
	Capsule->SetCapsuleRadius(15.f);
	SetRootComponent(Capsule);//equals to(	RootComponent = Capsule;)

	BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
	BirdMesh->SetupAttachment(GetRootComponent());
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}


void Abird::BeginPlay()
{
	Super::BeginPlay();
}

void Abird::MoveForward(float value)
{

}

void Abird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void Abird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


}

