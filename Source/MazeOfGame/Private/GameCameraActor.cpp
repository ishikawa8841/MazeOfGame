// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeOfGame.h"
#include "GameCameraActor.h"

void AGameCameraActor::Tick(float DeltaSeconds)
{
	FVector lookAtPos(0, 0, 0);
	if (m_Target){
		//����ׂ��^�[�Q�b�g�ʒu
		lookAtPos = m_Target->GetRootComponent()->GetComponentLocation();
	}

	//�J�����ʒu�v�Z
	FVector targetCameraPos = lookAtPos + m_OffsetFromTarget;

	//���݂̃J�����ʒu
	FVector currentCameraPos = this->GetActorLocation();

	//���݈ʒu�v�Z
	targetCameraPos = (targetCameraPos * 0.1f) + (currentCameraPos * 0.9f);

	//�ʒu���X�V
	this->SetActorRotation( (lookAtPos - targetCameraPos).Rotation() );
	this->GetRootComponent()->SetWorldLocation(targetCameraPos);

}



