// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeOfGame.h"
#include "MyHUD.h"
#include "MyWorldSettings.h"

void AMyHUD::DrawHUD()
{
	UWorld* const world = GetWorld();

	//�`�������			

	//2D�e�L�X�g�\��
	FString Text = "TEST";
	FVector2D Position(-1,-1);
	UFont* TextFont = ((AMyWorldSettings*)(world->GetWorldSettings()))->GetUIFont();
	FVector2D FontScale(1,1);
	FColor TextColor(255,255,255);
	DrawText(Text, Position, TextFont, FontScale, TextColor);

	//���\��
	DrawRect(FLinearColor(1, 1, 1), 0, 0, 100, 100);

}

