// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeOfGame.h"
#include "MazeOfGameGameMode.h"


AMazeOfGameGameMode::AMazeOfGameGameMode()
{
	//スタート時のPawnは自分で作りたいので、作らせないようにする
	DefaultPawnClass = NULL;
}
