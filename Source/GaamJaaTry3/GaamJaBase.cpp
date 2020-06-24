// Fill out your copyright notice in the Description page of Project Settings.

#include "Engine/Classes/Components/CapsuleComponent.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "Engine/Classes/GameFramework/CharacterMovementComponent.h"
#include "Engine/Classes/GameFramework/SpringArmComponent.h"

#include "GaamJaBase.h"

// Sets default values
AGaamJaBase::AGaamJaBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	RpgCameraSpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("RpgCameraSpringArm"));
	RpgCameraSpringArmComponent->SetupAttachment(RootComponent);
	//RpgCameraSpringArmComponent->bAbsoluteRotation = true;
	RpgCameraSpringArmComponent->TargetArmLength = 800.0f;
	//RpgCameraSpringArmComponent->RelativeRotation = FRotator(-60.0f, 45.0f, 0.0f);
	RpgCameraSpringArmComponent->bDoCollisionTest = false;

	RpgCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("RpgCamera"));
	RpgCameraComponent->SetupAttachment(RpgCameraSpringArmComponent, USpringArmComponent::SocketName);
	RpgCameraComponent->bUsePawnControlRotation = false;

	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void AGaamJaBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGaamJaBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGaamJaBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

