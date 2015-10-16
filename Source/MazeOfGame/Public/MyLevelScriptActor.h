// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/LevelScriptActor.h"
#include "MyLevelScriptActor.generated.h"

class AGameCameraActor;

/**
 * 
 */
UCLASS()
class MAZEOFGAME_API AMyLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

	AActor *m_Player;
	AGameCameraActor *m_Camera;

	virtual void BeginPlay();
	virtual void Tick(float DeltaSeconds) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);

};
