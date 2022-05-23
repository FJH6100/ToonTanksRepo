// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class TOONTANKS_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent * ProjectileMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UParticleSystemComponent * FollowTrail;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UProjectileMovementComponent * PMovement;

	FTimerHandle ProjectileTimerHandle;

	UPROPERTY(EditDefaultsOnly)
	float ProjectileLife = 2;

	UPROPERTY(EditAnywhere)
	float Damage = 50;

	UPROPERTY(EditAnywhere)
	class UParticleSystem * HitParticles;

	UPROPERTY(EditAnywhere)
	class USoundBase * LaunchSound;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class UCameraShakeBase> CameraShakeClass;

	UPROPERTY(EditAnywhere)
	USoundBase * HitSound;

	void DestroySelf();

	UFUNCTION()
	void OnHit(UPrimitiveComponent * HitComp, AActor* OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
