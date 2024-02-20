// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BallSphere = CreateDefaultSubobject<USphereComponent>(TEXT("BallSphere"));
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BallMesh"));
	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Projectile"));
	SetRootComponent(BallSphere);
	BallMesh->SetupAttachment(RootComponent);

	Projectile->ProjectileGravityScale = 0.f;
	Projectile->InitialSpeed = 1000.f;
	Projectile->MaxSpeed = 10000.f;
	Projectile->bShouldBounce = true;
	Projectile->Bounciness = 1.1;
	Projectile->Friction = 0.f;


	BallMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BallMesh->SetCollisionProfileName(TEXT("IgnoreAll"));

	BallSphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BallSphere->SetCollisionProfileName("BlockAllDynamic");

	BallSphere->GetBodyInstance()->bLockXRotation = true;
	BallSphere->GetBodyInstance()->bLockYRotation = true;
	BallSphere->GetBodyInstance()->bLockZRotation = true;
	BallSphere->GetBodyInstance()->bLockXTranslation = true;
	BallSphere->GetBodyInstance()->bLockZTranslation = true;

	BallSphere->SetLinearDamping(10);


}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

