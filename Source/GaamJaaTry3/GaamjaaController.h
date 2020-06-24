// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GaamjaaController.generated.h"

/**
 * 
 */
UCLASS()
class GAAMJAATRY3_API AGaamjaaController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AGaamjaaController();

protected:
	bool bClickMouse;

	void InputClickPressed();
	void InputClickReleased();

	virtual void SetupInputComponent()override;

	void SetNewDestination(const FVector DesLocation);

	void MoveToMouseCursor();

	virtual void PlayerTick(float DeltaTime)override;
};
