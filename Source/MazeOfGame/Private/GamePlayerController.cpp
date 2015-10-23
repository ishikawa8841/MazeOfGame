// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeOfGame.h"
#include "GamePlayerController.h"
#include "MyBallPawn.h"
#include "MyHud.h"

void AGamePlayerController::BeginPlay()
{
	Super::BeginPlay();

	//�Ō���Ԃɐݒ�
	m_control_mode = PLAYER_CONTROL_MODE_IPACT_SELECT;

	InputComponent->BindAxis("UP", this, &AGamePlayerController::Move_XCrossKey);
}

void AGamePlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	//PlayerPawn��ݒ肳�ꂽ�炱������R���g���[������
	((AmyBallPawn*)InPawn)->SetControlMode(AmyBallPawn::PLAYER_CONTROL_MODE_IPACT_SELECT);  ///< Pawn����Hud�Ɏi�߂��s���ăR���g���[�����Ă��炤
	//HUD�R���g���[��
	//((AMyHUD*)GetHUD())->
}

void AGamePlayerController::Tick(float DeltaTime)
{
	if (IsInputKeyDown(EKeys::Gamepad_DPad_Up)){
		UE_LOG(LogTemp, Log, TEXT("On Hit Call!"));
	}

	FlushPressedKeys();
}

void AGamePlayerController::Move_XCrossKey(float AxisValue)
{
}
void AGamePlayerController::Move_YCrossKey(float AxisValue)
{
}
