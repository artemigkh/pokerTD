//
// Created by Artem on 10/3/2017.
//

#ifndef POKERTD_TERRAIN_H
#define POKERTD_TERRAIN_H

#include <vector>
#include "../PlayState/TerrainTypes.h"
#include "../PlayState/HandsEnum.h"
#include "ActiveTower.h"

class Terrain {
public:
    Terrain(int x1, int y1, int x2, int y2, TerrainTypes terrainType);

    TerrainTypes getTerrainType() const;

    bool isSquareBuildable(int x, int y);

    int getX1() const;

    int getY1() const;

    int getX2() const;

    int getY2() const;

private:
    TerrainTypes terrainType;
    bool isBuildable;

    /*
     * each buildable terrain will have a 4x4 grid of buildable tiles
     * each tower will be 2x2
     */
    std::vector<ActiveTower*> towerSpaces;
    /*
     * (x1,y1)------+
     * |            |
     * +-----------(x2,y2)
    */
    int x1;
    int y1;
    int x2;
    int y2;
};


#endif //POKERTD_TERRAIN_H
