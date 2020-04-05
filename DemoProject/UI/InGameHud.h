// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Components/WidgetComponent.h"
#include "HealthBarWidget.h"
#include "InGameHud.generated.h"


/**
 * 
 */

// Class that contains all widgets to display
UCLASS()
class DEMOPROJECT_API AInGameHud : public AHUD
{
	GENERATED_BODY()
	
public: 
	

	AInGameHud();

	virtual void DrawHUD() override;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

/*	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> HealthBarWidgetClass;

	UHealthBarWidget* HealthBarWidget;*/
};
