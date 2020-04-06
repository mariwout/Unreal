// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Components/ProgressBar.h"
#include "Components/CanvasPanelSlot.h"
#include "Kismet/GameplayStatics.h"
#include "Math/Color.h"
#include "HealthBarWidget.generated.h"

/**
 * 
 */
UCLASS()
class DEMOPROJECT_API UHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// Constructor for the HealthBar Widget
	UHealthBarWidget(const FObjectInitializer& ObjectInitializer);
	
	// Main update function that is called by the owning character
	void UpdateHealthBar(float Value, FVector ActorLocation);

	// Function to update location of the Healthbar on-screen based on 3D coordinates
	void UpdateHealthBarLocation(FVector ActorLocation);

	// Function to update percentage of health bar based on percentage input 
	void UpdateHealthBarPercentage(float Value);

	// Toggle Health Bar visibility on or off
	void HealthBarVisibilityToggle();

	// Bound blueprint widget progressbar
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		class UProgressBar* HealthStatusBar;

private:
	// Private function to update color and opacity of Health Bar
	void UpdateHealthBarColorAndOpacity(FLinearColor HealthBarColorAndOpacity);

};
