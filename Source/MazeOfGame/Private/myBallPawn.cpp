// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeOfGame.h"
#include "Public/myBallPawn.h"
#include "MyWorldSettings.h"


// 操作キャラクタとなるボールの定義
// コントローラにより物理挙動の変更を行う
AmyBallPawn::AmyBallPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this pawn to be controlled by the lowest-numbered player (このポーンが最小値のプレイヤーで制御されるように設定)
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// Create a dummy root component we can attach things to.(親子付け可能なダミーのルートコンポーネントを作成)
	//RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//スタティックコンポーネント追加
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

	//物理挙動をONにする
	UStaticMeshComponent *static_mesh_component = ((UStaticMeshComponent*)OurVisibleComponent);

	AMyWorldSettings *game_setting = static_cast<AMyWorldSettings*>(GetWorldSettings());
	if (game_setting && game_setting->GetPlayerMesh()){
		//ボール型メッシュを割当
		static_mesh_component->SetStaticMesh(game_setting->GetPlayerMesh());
	}

	static_mesh_component->Mobility = EComponentMobility::Movable;
	static_mesh_component->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	static_mesh_component->BodyInstance.bSimulatePhysics = true;

	//Hitイベントを生成する為にはぶつかる方とぶつけられる方両方にこの設定が必要
	static_mesh_component->SetNotifyRigidBodyCollision(true);

	//最大速度を設定
	static_mesh_component->SetPhysicsMaxAngularVelocity(1.0f);


}

// Called when the game starts or when spawned
void AmyBallPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AmyBallPawn::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	UStaticMeshComponent *static_mesh_component = ((UStaticMeshComponent*)GetComponentByClass(UStaticMeshComponent::StaticClass()));
	USceneComponent *RootComponent = GetRootComponent();

	if (static_mesh_component){

		//FVector CurrentVelocity = static_mesh_component->GetComponentVelocity();

		//速度ベクトルが動いているか？
		if (!CurrentVelocity.IsZero())
		{
			//移動させる
			//FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
			static_mesh_component->BodyInstance.SetLinearVelocity(CurrentVelocity, true);

		}
		CurrentVelocity = FVector::ZeroVector;

		//カメラの位置を移動させるためRootComponentの位置を同じ位置に移動させる
		//RootComponent->SetWorldLocation(static_mesh_component->BodyInstance.GetCOMPosition());

		FVector velocity = static_mesh_component->GetComponentVelocity();

		//重力方向はつぶす
		velocity.Z = 0;

		//左右の速度を判定して一定の速度が出ている場合は上書きして速度を保つ
		if (velocity.Size() > 3000.0f){
			velocity.Normalize();
			velocity *= 3000.0f;
			static_mesh_component->BodyInstance.SetLinearVelocity(velocity, false);
		}
	}

}

// Called to bind functionality to input
void AmyBallPawn::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	//入力コントローラの割当を行っている　名前を設定してその対応をどの関すで行うかを記述する
	InputComponent->BindAxis("MoveX", this, &AmyBallPawn::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &AmyBallPawn::Move_YAxis);

}

//コントローラ入力
void AmyBallPawn::Move_XAxis(float AxisValue)
{
	//テスト入力です。場合によっては自分で動かす為
	ACameraActor* camera = dynamic_cast<ACameraActor*>(GetWorld()->GetFirstPlayerController()->GetViewTarget());
	if (camera){
		FVector right_vector = camera->GetCameraComponent()->GetRightVector();

		// Move at 100 units per second forward or backward (1 秒間に前後へ 100 単位移動)
		CurrentVelocity += (right_vector * FMath::Clamp(AxisValue, -1.0f, 1.0f) * 10.f);
	}
}

void AmyBallPawn::Move_YAxis(float AxisValue)
{
	//テスト入力です。場合によっては自分で動かす為
	ACameraActor* camera = dynamic_cast<ACameraActor*>(GetWorld()->GetFirstPlayerController()->GetViewTarget());
	if (camera){
		FVector forward_vector = camera->GetCameraComponent()->GetForwardVector();

		// Move at 100 units per second right or left (1 秒間に左右へ 100 単位移動)
		CurrentVelocity += (forward_vector * FMath::Clamp(AxisValue, -1.0f, 1.0f) * 10.f);
	}
}

void AmyBallPawn::OnHit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	//衝突された場合の判定
}

void AmyBallPawn::OnOrverLap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{

}
