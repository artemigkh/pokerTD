//
// Created by Artem on 10/3/2017.
//

#include <iostream>
#include <cstdio>
#include "../../include/Terrain.h"
#include "../../include/GameConstants.h"

Terrain::Terrain(int x1, int y1, int x2, int y2, TerrainTypes terrainType)
        : x1(x1), y1(y1), terrainType(terrainType), x2(x2), y2(y2) {
    isBuildable = (terrainType == BUILDABLE);
    activeTower = nullptr;
    isValidBuildState = false;
}

TerrainTypes Terrain::getTerrainType() const {
    return terrainType;
}

int Terrain::getX1() const {
    return x1;
}

int Terrain::getY1() const {
    return y1;
}

int Terrain::getX2() const {
    return x2;
}

int Terrain::getY2() const {
    return y2;
}

bool Terrain::isSquareBuildable() {
    return isBuildable && activeTower == nullptr;
}

void Terrain::placeTower(ActiveTower *tower) {
    activeTower = tower;
    isValidBuildState = false;
}

bool Terrain::isCoordinateInSquare(int x, int y) {
    return (x > x1 && x < x2 && y > y1 && y < y2);
}

void Terrain::previewPlaceTower() {
    isValidBuildState = true;
}

void Terrain::Update() {
    isValidBuildState = false;
    isInvalidBuildState = false;
}

bool Terrain::IsValidBuildState() const {
    return isValidBuildState;
}

bool Terrain::IsInvalidBuildState() const {
    return isInvalidBuildState;
}
