// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarWidget.h"

// Constructor class
UHealthBarWidget::UHealthBarWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {
}

// Function to update parameters of the health bar, such as percentage and location. 
void UHealthBarWidget::UpdateHealthBar(float Value, FVector ActorLocation)
{
	
	UpdateHealthBarPercentage(Value);
	UpdateHealthBarLocation(ActorLocation);
}

// Toggle Health Bar visibility on or off
void UHealthBarWidget::HealthBarVisibilityToggle()
{
	// If it is hidden, toggle it to visible
	if (HealthStatusBar->Visibility == ESlateVisibility::Hidden)
	{
		HealthStatusBar->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		// Else hide it
		HealthStatusBar->SetVisibility(ESlateVisibility::Hidden);
	}
}

// Function to update fill percentage of the health bar. 
void UHealthBarWidget::UpdateHealthBarPercentage(float Value)
{
	if (HealthStatusBar)
	{
		HealthStatusBar->SetPercent(Value);
		
		// Standard color is green
		FLinearColor HealthBarColorAndOpacity = FLinearColor(0, 1.f, 0);

		if (Value < 0.25)
		{
			// If Health is lower than 25%, set color to red
			HealthBarColorAndOpacity = FLinearColor(1.f, 0, 0);
		}
		else if (Value < 0.5)
		{
			// If Health is between 25% and 50%, set color to yellow
			HealthBarColorAndOpacity = FLinearColor(1.f, 1.f, 0);
		}

		// Call function to update color and opacity 
		UpdateHealthBarColorAndOpacity(HealthBarColorAndOpacity);
	}
}

// Private function to update color and opacity of Health Bar
void UHealthBarWidget::UpdateHealthBarColorAndOpacity(FLinearColor HealthBarColorAndOpacity)
{
	if (HealthStatusBar)
	{
		HealthStatusBar->SetFillColorAndOpacity(HealthBarColorAndOpacity);
	}
}

// Function to update location of the health bar using canvasslot
void UHealthBarWidget::UpdateHealthBarLocation(FVector ActorLocation)
{
	APlayerController* PController = GetWorld()->GetFirstPlayerController();

	// FVector2D to hold the widget screen location
	FVector2D WidgetScreenLocation;

	// Project the world actor location to the screenlocation
	if (UGameplayStatics::ProjectWorldToScreen(PController, ActorLocation, WidgetScreenLocation))
	{
		// Set the position of the widget
		this->SetPositionInViewport(WidgetScreenLocation);
	}
}