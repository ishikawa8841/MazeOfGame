// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeOfGame.h"
#include "GameCameraActor.h"

void AGameCameraActor::Tick(float DeltaSeconds)
{
	FVector lookAtPos(0, 0, 0);
	if (m_Target){
		//見るべきターゲット位置
		lookAtPos = m_Target->GetRootComponent()->GetComponentLocation();
	}

	//カメラ位置計算
	FVector targetCameraPos = lookAtPos + m_OffsetFromTarget;

	//現在のカメラ位置
	FVector currentCameraPos = this->GetActorLocation();

	//現在位置計算
	targetCameraPos = (targetCameraPos * 0.5f) + (currentCameraPos * 0.5f);

	//カメラの向きを計算する
	FVector camVec(lookAtPos-targetCameraPos);
	camVec.Normalize();
	FQuat camQRot = FQuat::FindBetween(FVector::ForwardVector, camVec);

	//アップベクトルの固定化
	FVector upVector = camQRot.RotateVector(FVector::UpVector);
	FQuat   upRot = FQuat::FindBetween(upVector,FVector::UpVector);
	camQRot = upRot * camQRot;

	//位置を更新
	this->GetRootComponent()->SetWorldLocation(targetCameraPos);
	this->GetRootComponent()->SetWorldRotation(camQRot);

}



