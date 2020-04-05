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

// Function to update fill percentage of the health bar. 
void UHealthBarWidget::UpdateHealthBarPercentage(float Value)
{
	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(Value);
	}
}

// Function to update location of the health bar using canvasslot
void UHealthBarWidget::UpdateHealthBarLocation(FVector ActorLocation)
{
	// Cast the canvas slot of the widget
	UCanvasPanelSlot* CanvasSlot = Cast< UCanvasPanelSlot >(HealthProgressBar->Slot);
	if (CanvasSlot) {
		APlayerController* PController = GetWorld()->GetFirstPlayerController();

		// FVector2D to hold the widget screen location
		FVector2D WidgetScreenLocation;

		// Project the world actor location to the screenlocation
		if (UGameplayStatics::ProjectWorldToScreen(PController, ActorLocation, WidgetScreenLocation))
		{
			//UE_LOG(LogTemp, Warning, TEXT("Location of the Widget on screen: x = %f, y = %f"), WidgetScreenLocation.X, WidgetScreenLocation.Y);
			//UE_LOG(LogTemp, Warning, TEXT("Actor location is: x = %f, y = %f, z = %f"), ActorLocation.X, ActorLocation.Y, ActorLocation.Z);

			// Set the position of the widget
			CanvasSlot->SetPosition(WidgetScreenLocation);
		}
	}
}