// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/WorldSettings.h"
#include "MyWorldSettings.generated.h"

/**
 * 
 */
UCLASS()
class MAZEOFGAME_API AMyWorldSettings : public AWorldSettings
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = BallSetting)
	UStaticMesh *m_PlayerMesh;

	UPROPERTY(EditAnywhere, Category = BallSetting)
	UStaticMesh *m_PlayerCollisionMesh;

public:
	UStaticMesh *GetPlayerMesh(){ return m_PlayerMesh; }
	UStaticMesh *GetPlayerCollisionMesh(){ return m_PlayerCollisionMesh; }

	
	
};
