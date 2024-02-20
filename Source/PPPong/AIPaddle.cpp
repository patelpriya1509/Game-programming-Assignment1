// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPaddle.h"
#include "Ball.h"
#include "Kismet/GameplayStatics.h"


void AAIPaddle::BeginPlay()
{
	Super::BeginPlay();

	BallRef = Cast<ABall>(UGameplayStatics::GetActorOfClass(GetWorld(), ABall::StaticClass()));
	
}

void AAIPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (BallRef != NULL) {
		FVector BallLocation = BallRef->GetActorLocation();
		FVector TargetLocation = GetActorLocation();
		TargetLocation.Z = BallLocation.Z;
		FVector NewLocation = FMath::VInterpConstantTo(TargetLocation, BallLocation, DeltaTime, 500.f);
		SetActorLocation(NewLocation);
	}
}