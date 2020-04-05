// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameHud.h"

AInGameHud::AInGameHud()
{

}

void AInGameHud::BeginPlay()
{
	Super::BeginPlay();
	/*
	HealthBarWidget = CreateWidget<UHealthBarWidget>(GetWorld(), HealthBarWidgetClass);
	if (HealthBarWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("HealthBarWidget created"));
		HealthBarWidget->AddToViewport();
	}*/
}

void AInGameHud::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AInGameHud::DrawHUD()
{
	Super::DrawHUD();
}
