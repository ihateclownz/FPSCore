// Copyright 2022 Ellie Kelemen. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionValue.h"
// ReSharper disable once CppUnusedIncludeDirective
#include "CharacterCore.h"
#include "WeaponBase.h"
#include "Components/InventoryComponent.h"
#include "Components/TimelineComponent.h"
#include "GameFramework/Character.h"
#include "FPSCharacter.generated.h"

UCLASS()
class FPSCORE_API AFPSCharacter : public ACharacterCore 
{
	GENERATED_BODY()

public:
	
	/** Returns the character's hands mesh */
	USkeletalMeshComponent* GetHandsMesh() const { return HandsMeshComp; }

	/** Returns a reference to the player's camera component */
	UCameraComponent* GetCameraComponent() const { return CameraComponent; }

	
protected:

	/** Function that actually executes the Vault
	 * @param TargetTransform The location to which to interpolate the player
	 */
	virtual void Vault(FTransform TargetTransform) override;

	/** The character's FPS camera component */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Components")
	UCameraComponent* CameraComponent;

	/** The character's hands mesh component */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Components")
	USkeletalMeshComponent* HandsMeshComp;
	
	/** The spring arm component, which is required to enable 'use control rotation' */
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	USpringArmComponent* SpringArmComponent;

#pragma region FUNCTIONS

	/** Sets default values for this character's properties */
	AFPSCharacter();

	/** Called when the game starts or when spawned */
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

#pragma endregion 

#pragma region USER_VARIABLES
		
#pragma endregion 

#pragma region INTERNAL_VARIABLES
	
	/** The default offset of the spring arm from a Z position of 0, set automatically on BeginPlay */
	float DefaultSpringArmOffset;
	
#pragma endregion 

#pragma region INPUT

#pragma endregion
};
