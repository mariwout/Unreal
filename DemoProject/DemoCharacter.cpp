// Fill out your copyright notice in the Description page of Project Settings.

#include "DemoCharacter.h"

// Sets default values
ADemoCharacter::ADemoCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ConstructorHelpers::FClassFinder<UUserWidget> HealthBarClassFinder(TEXT("/UI/BP_HealthBarWidget"));
	// TSubclassOf<UUserWidget> HealthBarWidgetClass = HealthBarClassFinder.Class;
}

// Called when the game starts or when spawned
void ADemoCharacter::BeginPlay()
{
	Super::BeginPlay();

	// Call function to initialize the health bar on this character
	InitializeHealthBar();
}

// Initialize a health bar on the character
void ADemoCharacter::InitializeHealthBar()
{
	// Create a healthbar widget of class HealthBarWidgetClass
	if (HealthBarWidgetClass)
	{
		HealthBarWidget = CreateWidget<UHealthBarWidget>(GetWorld(), HealthBarWidgetClass);

		// If the widget has been created, add it to the viewport
		if (HealthBarWidget)
		{
			HealthBarWidget->AddToViewport();
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("HealthBarWidget not created"));
			return;
		}
	}
}

// Called every frame
void ADemoCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Determine current actor location
	FVector ActorLocation = this->GetActorLocation();

	// Calculate Health percentage
	float HealthPercent = CurrentHealth / StartingHealth;

	// --- EXAMPLE --- reduce currentHealth by 1
	CurrentHealth = CurrentHealth - 1;

	// --- EXAMPLE --- Hide the Health Bar if there is no more health 
	if (CurrentHealth == 0)
	{
		HealthBarWidget->HealthBarVisibilityToggle();
	}

	// Call widget update function
	if (HealthBarWidget)
	{
		HealthBarWidget->UpdateHealthBar(HealthPercent, ActorLocation);
	}
}

// Called to bind functionality to input
void ADemoCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

