//
// Created by Artem on 10/3/2017.
//

#include "../../include/Terrain.h"

Terrain::Terrain(int x1, int y1, int y2, int x2, TerrainTypes terrainType)
        : x1(x1), y1(y1), terrainType(terrainType), x2(x2), y2(y2) {
    isBuildable = (terrainType == BUILDABLE);
}

TerrainTypes Terrain::getTerrainType() const {
    return terrainType;
}

bool Terrain::IsBuildable() const {
    return isBuildable;
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
