// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class MAZEOFGAME_API AMyHUD : public AHUD
{
	GENERATED_BODY()

	//ï`âÊèÊÇ¡éÊÇË			
	virtual void DrawHUD();

	float m_cursolX;
	float m_cursolY;
public:
	void SetCursolX(float x){ m_cursolX = x; }
	void SetCursolY(float y){ m_cursolY = y; }
	const float GetCursolX(){ return m_cursolX; }
	const float GetCursolY(){ return m_cursolY; }

};
