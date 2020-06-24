// Fill out your copyright notice in the Description page of Project Settings.

#include "Blueprint/AIBlueprintHelperLibrary.h"

#include "GaamjaaController.h"

AGaamjaaController::AGaamjaaController() 
{
	bShowMouseCursor = true;
}

void AGaamjaaController::InputClickPressed()
{
	bClickMouse = true;
}

void AGaamjaaController::InputClickReleased()
{
	bClickMouse = false;
}

void AGaamjaaController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("InputClick", IE_Pressed, this, &AGaamjaaController::InputClickPressed);
	InputComponent->BindAction("InputClick", IE_Released, this, &AGaamjaaController::InputClickReleased);
}

void AGaamjaaController::SetNewDestination(const FVector DesLocation)
{
	APawn* const MyPawn = GetPawn();

	if (MyPawn)
	{
		float const Distance = FVector::Dist(DesLocation, MyPawn->GetActorLocation());

		if (Distance > 120.0f)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DesLocation);
		}
	}
}

void AGaamjaaController::MoveToMouseCursor()
{
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	if (Hit.bBlockingHit)
	{
		SetNewDestination(Hit.ImpactPoint);
	}
}

void AGaamjaaController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (bClickMouse)
	{
		MoveToMouseCursor();
	}
}
