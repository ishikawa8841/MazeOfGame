// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeOfGame.h"
#include "MyLevelScriptActor.h"
#include "MyBallPawn.h"
#include "GameCameraActor.h"

DEFINE_LOG_CATEGORY_STATIC(LogGamePlay, Display, All);

//ゲーム開始時に呼ばれる
void AMyLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	//デバックとして一時的に表示出来る機構だそうです。結構便利かも
	GEngine->AddOnScreenDebugMessage(0, 2.0f, FLinearColor::Red.ToFColor(true),TEXT("Hello World"));

	UWorld* const world = GetWorld();

	//マップ内スタート位置検索
	FVector player_start;
	for (TActorIterator<APlayerStart> It(world); It; ++It)
	{
		player_start = (*It)->GetActorLocation();
	}

	//カメラを作成
	myCamera = world->SpawnActor(AGameCameraActor::StaticClass(), &player_start);
	//メインカメラに指定
	world->GetFirstPlayerController()->SetViewTargetWithBlend(myCamera);

	//プレイヤをスポーンする
	APawn *pawn = static_cast<APawn*>(world->SpawnActor(AmyBallPawn::StaticClass(), &player_start));
	myPlayer = pawn;
}


void AMyLevelScriptActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//ゲーム完了時に呼ばれる
void AMyLevelScriptActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	myCamera = NULL;
	myPlayer = NULL;
}
