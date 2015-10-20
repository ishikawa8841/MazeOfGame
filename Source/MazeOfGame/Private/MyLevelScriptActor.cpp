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
	FVector  player_start;
	FRotator player_rotate;
	for (TActorIterator<APlayerStart> It(world); It; ++It)
	{
		player_start = (*It)->GetActorLocation();
		player_rotate = (*It)->GetActorRotation();
	}

	//プレイヤをスポーンする
	FActorSpawnParameters params;
	params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;			///< 作成時にコリジョンを見ないようにして作成させる（色々やったが何故か衝突して作れない）
	APawn *pawn = static_cast<APawn*>(world->SpawnActor(AmyBallPawn::StaticClass(), &player_start, &player_rotate, params));
	m_Player = pawn;

	//カメラを作成
	m_Camera = (AGameCameraActor*)world->SpawnActor(AGameCameraActor::StaticClass(), &player_start);

	//カメラ距離指定
	m_Camera->SetOffsetFromTarget( FVector(1200, 1200, 0) );
	m_Camera->SetTarget(m_Player);

	//メインカメラに指定
	world->GetFirstPlayerController()->SetViewTargetWithBlend(m_Camera);


}


void AMyLevelScriptActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//ゲーム完了時に呼ばれる
void AMyLevelScriptActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	m_Camera = NULL;
	m_Player = NULL;
}
