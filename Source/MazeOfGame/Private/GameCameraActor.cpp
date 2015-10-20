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
	targetCameraPos = (targetCameraPos * 0.5f) + (currentCameraPos * 0.5f);

	//�J�����̌������v�Z����
	FVector camVec(lookAtPos-targetCameraPos);
	camVec.Normalize();
	FQuat camQRot = FQuat::FindBetween(FVector::ForwardVector, camVec);

	//�A�b�v�x�N�g���̌Œ艻
	FVector upVector = camQRot.RotateVector(FVector::UpVector);
	FQuat   upRot = FQuat::FindBetween(upVector,FVector::UpVector);
	camQRot = upRot * camQRot;

	//�ʒu���X�V
	this->GetRootComponent()->SetWorldLocation(targetCameraPos);
	this->GetRootComponent()->SetWorldRotation(camQRot);

}



