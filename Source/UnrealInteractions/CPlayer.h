// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CPlayer.generated.h"

UCLASS()
class UNREALINTERACTIONS_API ACPlayer : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float movespeed{};
	FVector* direction{new FVector()};

	void HorizontalAxis(float value);
	void VerticalAxis(float value);

	UFUNCTION()
	void OnOverlap(AActor* self, AActor* other);

public:
	// Sets default values for this character's properties
	ACPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
