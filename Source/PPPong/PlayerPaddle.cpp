// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPaddle.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"
#include "EngineUtils.h"

// Sets default values
APlayerPaddle::APlayerPaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<UBoxComponent>(TEXT("Root"));
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualMesh"));
	Root->SetSimulatePhysics(true);
	SetRootComponent(Root);
	//Root->SetupAttachment(RootComponent);
	VisualMesh->SetupAttachment(Root);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	VisualMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	VisualMesh->SetCollisionProfileName(TEXT("IgnoreAll"));

	Root->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Root->SetCollisionProfileName("Pawn");

	Root->GetBodyInstance()->bLockXRotation = true;
	Root->GetBodyInstance()->bLockYRotation = true;
	Root->GetBodyInstance()->bLockZRotation = true;
	Root->GetBodyInstance()->bLockXTranslation = true;
	Root->GetBodyInstance()->bLockYTranslation = true;

	Root->SetLinearDamping(10);
}

// Called when the game starts or when spawned
void APlayerPaddle::BeginPlay()
{
	Super::BeginPlay();

	AActor* Camera = UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass());

	if (Camera != nullptr) {
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (PC != nullptr) {
			PC->SetViewTargetWithBlend(Camera, 3.f, EViewTargetBlendFunction::VTBlend_Cubic);
		}
	}
	
}

// Called every frame
void APlayerPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetController() != nullptr) {
		FRotator Rotation(0.f, GetControlRotation().Yaw, 0.f);
		FVector Direction = FVector::ZeroVector;

		if (MoveUpAmount != 0) {
			Direction = GetActorLocation() + GetActorUpVector() * MoveUpAmount * Velocity * DeltaTime;
			SetActorLocation(Direction);
		}
	}

}

// Called to bind functionality to input
void APlayerPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	AActor* Camera = UGameplayStatics::GetActorOfClass(GetWorld(), ACameraActor::StaticClass());

	if (Camera != nullptr) {
		APlayerController* PC = GetWorld()->GetFirstPlayerController();
		if (PC != nullptr) {
			PC->SetViewTargetWithBlend(Camera, 3.f, EViewTargetBlendFunction::VTBlend_Cubic);
		}
	}
	if (PlayerInputComponent)
	{
		//BIND axis "MoveForward" to this objects MoveForward() Function
		PlayerInputComponent->BindAxis("MoveUp", this, &APlayerPaddle::MoveUp);

	}
}

void APlayerPaddle::MoveUp(float Amount)
{
	MoveUpAmount = Amount;
}

