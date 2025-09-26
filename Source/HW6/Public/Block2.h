// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Block2.generated.h"

UCLASS()
class HW6_API ABlock2 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlock2();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Block2|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Block2|Components")
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Block2|Properties")
	float MoveSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Block2|Properties")
	float MaxHeight;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Block2|Properties")
	float MinHeight;
	bool GoUp;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
