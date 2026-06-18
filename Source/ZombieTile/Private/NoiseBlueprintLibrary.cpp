// Fill out your copyright notice in the Description page of Project Settings.


#include "NoiseBlueprintLibrary.h"

//GetPerlinNoise2D Definition
float UNoiseBlueprintLibrary::GetPerlinNoise2D(FVector2D Location)
{
    return FMath::PerlinNoise2D(Location);
}
//GetVoronoiDistance2D Definition
void UNoiseBlueprintLibrary::GetVoronoiDistance2D(
    FVector2D Location,
    int32 Seed,
    float& Distance,
    int32& CellID
)
{
    const int32 CellX = FMath::FloorToInt(Location.X);
    const int32 CellY = FMath::FloorToInt(Location.Y);

    float ClosestDistanceSquared = FLT_MAX;
    int32 ClosestCellX = 0;
    int32 ClosestCellY = 0;

    for (int32 OffsetY = -1; OffsetY <= 1; OffsetY++)
    {
        for (int32 OffsetX = -1; OffsetX <= 1; OffsetX++)
        {
            const int32 CheckCellX = CellX + OffsetX;
            const int32 CheckCellY = CellY + OffsetY;

            const int32 CellSeed = HashCombineFastInt(
                HashCombineFastInt(Seed, CheckCellX),
                CheckCellY
            );

            FRandomStream Stream(CellSeed);

            const float PointX = CheckCellX + Stream.FRand();
            const float PointY = CheckCellY + Stream.FRand();

            const float DeltaX = Location.X - PointX;
            const float DeltaY = Location.Y - PointY;

            const float DistanceSquared = (DeltaX * DeltaX) + (DeltaY * DeltaY);

            if (DistanceSquared < ClosestDistanceSquared)
            {
                ClosestDistanceSquared = DistanceSquared;
                ClosestCellX = CheckCellX;
                ClosestCellY = CheckCellY;
            }
        }
    }

    Distance = FMath::Sqrt(ClosestDistanceSquared);

    CellID = HashCombineFastInt(
        HashCombineFastInt(Seed, ClosestCellX),
        ClosestCellY
    );
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