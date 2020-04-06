// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/WidgetComponent.h"
#include "UI/HealthBarWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "DemoCharacter.generated.h"

UCLASS()
class DEMOPROJECT_API ADemoCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "Health")
		float CurrentHealth = 100;

	UPROPERTY(EditAnywhere, Category = "Health")
		float StartingHealth = 100;

	// Sets default values for this character's properties
	ADemoCharacter();
	void InitializeHealthBar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Widget class reference
	// ConstructorHelpers::FClassFinder<UUserWidget> HealthBarClassFinder(TEXT("/UI/BP_HealthBarWidget"));

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UUserWidget> HealthBarWidgetClass;// = HealthBarClassFinder.Class;

	// C++ widget pointer
	UHealthBarWidget* HealthBarWidget;
};
