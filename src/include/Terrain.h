//
// Created by Artem on 10/3/2017.
//

#ifndef POKERTD_TERRAIN_H
#define POKERTD_TERRAIN_H

#include <vector>
#include "../PlayState/TerrainTypes.h"
#include "HandsEnum.h"
#include "ActiveTower.h"

class Terrain {
public:
    Terrain(int x1, int y1, int x2, int y2, TerrainTypes terrainType);

    TerrainTypes getTerrainType() const;

    bool isCoordinateInSquare(int x, int y);
    bool isSquareBuildable();

    void Update();

    void previewPlaceTower();
    void placeTower(ActiveTower* tower);

    int getX1() const;
    int getY1() const;
    int getX2() const;
    int getY2() const;

    bool IsValidBuildState() const;

    bool IsInvalidBuildState() const;

private:
    TerrainTypes terrainType;
    bool isBuildable;
    int x1;
    int y1;
    int x2;
    int y2;
    bool isValidBuildState;
    bool isInvalidBuildState;
    ActiveTower* activeTower;

};


#endif //POKERTD_TERRAIN_H
