// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "myBallPawn.generated.h"

UCLASS()
class MAZEOFGAME_API AmyBallPawn : public APawn
{
	GENERATED_BODY()

public:			
	enum PLAYER_CONTROL_MODE {
		PLAYER_CONTROL_MODE_NONE,			//コントロール出来ないモード
		PLAYER_CONTROL_MODE_IPACT_SELECT,	//HUDを介して打撃コントロール状態
	};

	void SetControlMode(PLAYER_CONTROL_MODE mode);

private:
	PLAYER_CONTROL_MODE m_controlmode;		//コントロールモード

public:
	// Sets default values for this pawn's properties
	AmyBallPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;

	FVector CurrentVelocity;

	// コントローラの入力を割当するAPI
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//コントローラ入力
	void Move_XAxis(float AxisValue);			///< 左右移動キー
	void Move_YAxis(float AxisValue);			///< 上下移動キー

	UFUNCTION()
	void OnHit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void OnOrverLap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
