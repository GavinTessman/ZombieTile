// Fill out your copyright notice in the Description page of Project Settings.


#include "NoiseBlueprintLibrary.h"

//GetPerlinNoise2D Definition
float UNoiseBlueprintLibrary::GetPerlinNoise2D(FVector2D Location)
{
    return FMath::PerlinNoise2D(Location);
}
//HashCombineFastInt Definition
int32 UNoiseBlueprintLibrary::HashCombineFastInt(int32 A, int32 B)
{
    return (int32)HashCombineFast(
        GetTypeHash(A),
        GetTypeHash(B)
    );
}
//GetHashInt Definition
int32 UNoiseBlueprintLibrary::GetHashInt(int32 Value)
{
    return GetTypeHash(Value);
}
//GetHashFloat Definition
float UNoiseBlueprintLibrary::GetHashFloat(float Value)
{
    return GetTypeHash(Value);
}