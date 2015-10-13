// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeOfGame.h"
#include "public/BounceBlock.h"


// Sets default values
ABounceBlock::ABounceBlock()
{
 	// 毎フレームTickを回すために必要な設定です
	PrimaryActorTick.bCanEverTick = true;

	//メッシュ設定を与える（計上はEditorからにしてみた）
	m_MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	//Hitイベントを生成する為にはぶつかる方とぶつけられる方両方にこの設定が必要
	m_MeshComponent->SetNotifyRigidBodyCollision(true);
	//Hitイベントを受け取る関数を登録
	m_MeshComponent->OnComponentHit.AddDynamic(this, &ABounceBlock::OnHit);
	//m_MeshComponent->OnComponentBeginOverlap.AddDynamic(this, &ABounceBlock::OnOrverLap);

	RootComponent = m_MeshComponent;
}

// Called when the game starts or when spawned
void ABounceBlock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABounceBlock::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}

void ABounceBlock::OnHit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//衝突された場合の判定
	UE_LOG(LogTemp, Log, TEXT("On Hit Call!"));

	//弾き返す！！
	OtherComp->AddImpulseAtLocation(NormalImpulse * 2.0f, Hit.Location);
}

void ABounceBlock::OnOrverLap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("On OrverLap Call!"));
}
