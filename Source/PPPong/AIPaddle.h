// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerPaddle.h"
#include "AIPaddle.generated.h"

/**
 * 
 */
UCLASS()
class PPPONG_API AAIPaddle : public APlayerPaddle
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	class ABall* BallRef;
};
