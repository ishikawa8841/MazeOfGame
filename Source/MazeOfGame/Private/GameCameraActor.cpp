// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeOfGame.h"
#include "GameCameraActor.h"

void AGameCameraActor::Tick(float DeltaSeconds)
{
	FVector lookAtPos(0, 0, 0);
	if (m_Target){
		//����ׂ��^�[�Q�b�g�ʒu
		FVector lookAtPos = m_Target->GetActorLocation();
	}

	//�J�����ʒu�v�Z
	FVector targetCameraPos = lookAtPos + m_OffsetFromTarget;

	//���݂̃J�����ʒu
	FVector currentCameraPos = this->GetActorLocation();

	//���݈ʒu�v�Z
	targetCameraPos = (targetCameraPos * 0.8f) + (currentCameraPos * 0.2f);

	//�ʒu���X�V
	this->SetActorLocation(targetCameraPos);
}



