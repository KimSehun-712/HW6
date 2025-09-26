// Fill out your copyright notice in the Description page of Project Settings.


#include "Block2.h"

// Sets default values
ABlock2::ABlock2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	// /Script/Engine.StaticMesh'/Game/Resources/Shapes/Shape_Cube.Shape_Cube'
	// /Script/Engine.Material'/Game/Resources/Materials/M_Concrete_Grime.M_Concrete_Grime'
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Shapes/Shape_Cube.Shape_Cube"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Materials/M_Concrete_Grime.M_Concrete_Grime"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	MoveSpeed = 100.0f;
}

// Called when the game starts or when spawned
void ABlock2::BeginPlay()
{
	Super::BeginPlay();
	
	float InitialZ = GetActorLocation().Z;
	GoUp = true;
	MinHeight = InitialZ;
	MaxHeight = InitialZ + 700.0f;
}

// Called every frame
void ABlock2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		if (GoUp)
		{
			AddActorLocalOffset(FVector(0.0f, 0.0f, MoveSpeed * DeltaTime));
			if (GetActorLocation().Z > MaxHeight)
			{
				GoUp = false;
			}
		}
		else
		{
			AddActorLocalOffset(FVector(0.0f, 0.0f, -MoveSpeed * DeltaTime));
			if (GetActorLocation().Z < MinHeight)
			{
				GoUp = true;
			}
		}		
	}
}

