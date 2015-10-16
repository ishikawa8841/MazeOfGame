// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Camera/CameraActor.h"
#include "GameCameraActor.generated.h"

/**
 * 
 */
UCLASS()
class MAZEOFGAME_API AGameCameraActor : public ACameraActor
{
	GENERATED_BODY()

	
		virtual void Tick( float DeltaSeconds );

		AActor* m_Target;										///<�J�������ǂ�������ׂ�Actor
		FVector	m_OffsetFromTarget;								///<Actor����̃I�t�Z�b�g�w��

public:
	
	void SetTarget(AActor* target){ m_Target = target; }
	void SetOffsetFromTarget(const FVector &offset){ m_OffsetFromTarget = offset; }

};
