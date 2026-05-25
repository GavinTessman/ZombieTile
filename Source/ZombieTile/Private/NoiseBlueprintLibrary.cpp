// Fill out your copyright notice in the Description page of Project Settings.


#include "NoiseBlueprintLibrary.h"

float UNoiseBlueprintLibrary::GetPerlinNoise2D(FVector2D Location)
{
    return FMath::PerlinNoise2D(Location);
}
