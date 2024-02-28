// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "SoulsRip/Public/DebugMacros.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("Begin Play Called!"));

	//if ( GEngine ) 
	//{
	//	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, FString("Item OnScreen Message!"));
	//}

	//UWorld* World = GetWorld();
	//FVector Location = GetActorLocation();
	//FVector Forward = GetActorForwardVector();

	//if (World) 
	//{
	//	//DrawDebugSphere(World, Location, 25.f, 24, FColor::Red, false, 30.f);
	//	//DrawDebugLine(World, Location, Location + Forward * 100.f, FColor::Red, true, -1.f, 0, 1.f);
	//	//DrawDebugPoint(World, Location + Forward * 100.f, 15.f, FColor::Red, true);
	//}

	//DRAW_SPHERE(Location);
	//DRAW_LINE(Location, Location + Forward * 100.f);
	//DRAW_POINT(Location + Forward * 100.f);
	//DRAW_VECTOR(Location, Location + Forward * 100.f);
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//UE_LOG( LogTemp, Warning, TEXT("Delta Time %f"), DeltaTime);

	//if (GEngine) 
	//{
	//	FString Name = GetName();
	//	FString Message = FString::Printf(TEXT("Item Name %s"), *Name);
	//	GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, Message);
	//	UE_LOG(LogTemp, Warning, TEXT("Item Name %s"), *Name);
	//}

		// Movement rate in units of cm/s
	float MovementRate = 50.f;
	float RotationRate = 45.f;

	// MovementRate * DeltaTime (cm/s) * (s/frame) = (cm/frame)
	AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
	AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
	DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);
}

