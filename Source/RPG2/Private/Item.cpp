// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include"DrawDebugHelpers.h"
#include"RPG2/DebugMacros.h"


AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;
}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	int32 AvgInt= Avg<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3:%d"), AvgInt);

	float Avgfloat = Avg<float>(1.1f, 3.3f);
	UE_LOG(LogTemp, Warning, TEXT("Avg of 1 and 3:%f"), Avgfloat);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

float AItem::TransformedSin()
{
	return Amplitude* FMath::Sin(RunningTime * TimeConstant);
}

//AddOnScreenDebugMessage 输出fstring 
//通过调用 TEXT构造fstring ，可输入额外参数
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	float RotationRate = 30.f;
	//RotationRate*deltatime =(degree/s)*(s/frame)=(degree/frame)

	AddActorWorldRotation(FRotator(0.f, 0.f, RotationRate * DeltaTime));

}

