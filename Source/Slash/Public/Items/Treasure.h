// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Treasure.generated.h"

class USoundBase;
class USceneComponent;

UCLASS()
class SLASH_API ATreasure : public AItem
{
    GENERATED_BODY()

public:
    ATreasure();

    virtual void Tick(float DeltaTime) override;

protected:
    virtual void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent,  //
        AActor* OtherActor,                                                      //
        UPrimitiveComponent* OtherComp,                                          //
        int32 OtherBodyIndex,                                                    //
        bool bFromSweep,                                                         //
        const FHitResult& SweepResult) override;

private:
    UPROPERTY(VisibleAnywhere)
    USceneComponent* SceneComponent;

    UPROPERTY(EditAnywhere, Category = "Treasure Properties", meta = (ClampMin = 1))
    int32 Gold = 1;

public:
    FORCEINLINE int32 GetGold() const { return Gold; }
};
