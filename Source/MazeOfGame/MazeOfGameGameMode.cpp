// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeOfGame.h"
#include "MazeOfGameGameMode.h"
#include "MyHUD.h"
#include "GamePlayerController.h"


AMazeOfGameGameMode::AMazeOfGameGameMode()
{
	//スタート時のPawnは自分で作りたいので、作らせないようにする
	DefaultPawnClass = NULL;
		
	//HUDも自分のもので置き換えする
	HUDClass = AMyHUD::StaticClass();
	PlayerControllerClass = AGamePlayerController::StaticClass();

}
