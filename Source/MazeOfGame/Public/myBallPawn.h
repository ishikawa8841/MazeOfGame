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
		PLAYER_CONTROL_MODE_NONE,			//�R���g���[���o���Ȃ����[�h
		PLAYER_CONTROL_MODE_IPACT_SELECT,	//HUD����đŌ��R���g���[�����
	};

	void SetControlMode(PLAYER_CONTROL_MODE mode);

private:
	PLAYER_CONTROL_MODE m_controlmode;		//�R���g���[�����[�h

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

	// �R���g���[���̓��͂���������API
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//�R���g���[������
	void Move_XAxis(float AxisValue);			///< ���E�ړ��L�[
	void Move_YAxis(float AxisValue);			///< �㉺�ړ��L�[

	UFUNCTION()
	void OnHit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void OnOrverLap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
