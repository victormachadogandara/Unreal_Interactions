// Fill out your copyright notice in the Description page of Project Settings.


#include "CPlayer.h"

// Sets default values
ACPlayer::ACPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &ACPlayer::OnOverlap);
}

// Called every frame
void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AddMovementInput(*direction * movespeed * DeltaTime);
}

// Called to bind functionality to input
void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("Horizontal", this, &ACPlayer::HorizontalAxis);
	PlayerInputComponent->BindAxis("Vertical", this, &ACPlayer::VerticalAxis);
}

void ACPlayer::HorizontalAxis(float value)
{
	direction->Y = value;
}

void ACPlayer::VerticalAxis(float value)
{
	direction->X = value;
}

void ACPlayer::OnOverlap(AActor* self, AActor* other)
{
	if (other->ActorHasTag("coin"))
	{
		other->Destroy();
	}
}