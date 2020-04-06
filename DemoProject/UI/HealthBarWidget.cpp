// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarWidget.h"

// Constructor class
UHealthBarWidget::UHealthBarWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer) {
}

// Function to update parameters of the health bar, such as percentage and location. 
void UHealthBarWidget::UpdateHealthBar(float Value)
{
	UpdateHealthBarPercentage(Value);
	UpdateHealthBarLocation();
}

// Toggle Health Bar visibility on or off
void UHealthBarWidget::HealthBarVisibilityToggle()
{
	if (HealthStatusBar) {
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
}

// Bind widget to actor and add to viewport in correct size
void UHealthBarWidget::Setup(AActor* NewOwner)
{
	if (OwningActor == NewOwner)
	{
		// Skip repeated calls
		return;
	}
	OwningActor = NewOwner;

	// Add widget to viewport
	this->AddToViewport();

	// Get size of owning actor to determine widget width
	FVector ActorBoundingBoxSize = OwningActor->GetComponentsBoundingBox().GetSize();
	FVector2D DesiredSize = FVector2D(ActorBoundingBoxSize.X, WidgetHeight);

	// Set desired size
	this->SetHealthBarSize(DesiredSize);
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
void UHealthBarWidget::UpdateHealthBarLocation()
{
	APlayerController* PController = GetWorld()->GetFirstPlayerController();

	// FVector2D to hold the widget screen location
	FVector2D WidgetScreenLocation;

	// Get size of owning actor to determine widget offset
	FVector ActorBoundingBoxSize = OwningActor->GetComponentsBoundingBox().GetSize();
	float HealthBarOffset = ActorBoundingBoxSize.Z / 4 * 3;

	FVector ActorLocation = OwningActor->GetActorLocation();
	ActorLocation.Z = ActorLocation.Z + HealthBarOffset;

	// Project the world actor location to the screenlocation
	if (UGameplayStatics::ProjectWorldToScreen(PController, ActorLocation, WidgetScreenLocation))
	{
		// Set the position of the widget
		this->SetPositionInViewport(WidgetScreenLocation);
	}
}

// Setup HealthBar size 
void UHealthBarWidget::SetHealthBarSize(FVector2D DesiredSize)
{
	UCanvasPanelSlot* CanvasSlot = Cast< UCanvasPanelSlot >(HealthStatusBar->Slot);

	if (CanvasSlot) {
		CanvasSlot->SetSize(DesiredSize);
	}
}