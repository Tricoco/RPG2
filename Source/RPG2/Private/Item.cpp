// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include"DrawDebugHelpers.h"
#include"RPG2/DebugMacros.h"


AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Begin Play called!"));

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Item OnScreen Message!"));
	}


	

}

//AddOnScreenDebugMessage 输出fstring 
//通过调用 TEXT构造fstring ，可输入额外参数
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("DeletaTime:%f"),DeltaTime);

	if (GEngine)
	{
		FString name = GetName();
		FString Message = FString::Printf(TEXT("DeltaTime:%f"), DeltaTime);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan,Message);

		UE_LOG(LogTemp, Warning, TEXT("DeletaTime:%s"), *name);
	}
	//Movement rate in units of cm/s
	float MovementRate = 50.f;
	float RotationRate = 45.f;

	//MovementRate * DeltaTIme (cm/s)*(s/frame)=(cm/frame)
	AddActorWorldOffset(FVector(MovementRate*DeltaTime, 0.f, 0.f));
	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(),GetActorLocation() + GetActorForwardVector() * 100)


}

