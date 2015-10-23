// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MAZEOFGAME_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	enum PLAYER_CONTROL_MODE {
		PLAYER_CONTROL_MODE_NONE,			//�R���g���[���o���Ȃ����[�h
		PLAYER_CONTROL_MODE_IPACT_SELECT,	//HUD����đŌ��R���g���[�����
	};

private:
	PLAYER_CONTROL_MODE m_control_mode;

	virtual void BeginPlay();
	virtual void SetPawn(APawn* InPawn);
	virtual void Tick(float DeltaTime);
	
	void Move_XCrossKey(float AxisValue);
	void Move_YCrossKey(float AxisValue);

};
