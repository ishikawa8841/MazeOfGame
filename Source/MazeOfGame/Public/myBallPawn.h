// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "myBallPawn.generated.h"

UCLASS()
class MAZEOFGAME_API AmyBallPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AmyBallPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//ÉRÉìÉgÉçÅ[Éâì¸óÕ
	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);

	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;
	UCameraComponent* m_camera;

	FVector CurrentVelocity;

	UFUNCTION()
	void OnHit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	void OnOrverLap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

};
