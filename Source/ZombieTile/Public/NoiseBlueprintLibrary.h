// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NoiseBlueprintLibrary.generated.h"

/**
 * 
 */
UCLASS()
class ZOMBIETILE_API UNoiseBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	//GetPerlinNoise2D declaration
	UFUNCTION(BlueprintCallable, Category = "World Generation")
	static float GetPerlinNoise2D(FVector2D Location);
	//HashCombineFastInt declaration
	UFUNCTION(BlueprintCallable, Category = "Hash")
	static int32 HashCombineFastInt(int32 A, int32 B);
};
