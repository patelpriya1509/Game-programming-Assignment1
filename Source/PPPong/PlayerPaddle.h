// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPaddle.generated.h"

UCLASS()
class PPPONG_API APlayerPaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPaddle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "PlayerPaddle")
	class UBoxComponent* Root;

	UPROPERTY(EditAnywhere, Category = "PlayerPaddle")
	class UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere, Category = "PlayerPaddle")
	float Velocity = 300.0f;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	float MoveUpAmount = 0;
	
	void MoveUp(float Amount);

};
