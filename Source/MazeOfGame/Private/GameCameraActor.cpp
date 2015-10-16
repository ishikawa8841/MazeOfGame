// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeOfGame.h"
#include "GameCameraActor.h"

void AGameCameraActor::Tick(float DeltaSeconds)
{
	FVector lookAtPos(0, 0, 0);
	if (m_Target){
		//見るべきターゲット位置
		FVector lookAtPos = m_Target->GetActorLocation();
	}

	//カメラ位置計算
	FVector targetCameraPos = lookAtPos + m_OffsetFromTarget;

	//現在のカメラ位置
	FVector currentCameraPos = this->GetActorLocation();

	//現在位置計算
	targetCameraPos = (targetCameraPos * 0.8f) + (currentCameraPos * 0.2f);

	//位置を更新
	this->SetActorLocation(targetCameraPos);
}



