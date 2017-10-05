//
// Created by Artem on 10/3/2017.
//

#ifndef POKERTD_TERRAIN_H
#define POKERTD_TERRAIN_H

#include "../PlayState/TerrainTypes.h"

class Terrain {
public:
    Terrain(int x1, int y1, int x2, int y2, TerrainTypes terrainType);

private:
    TerrainTypes terrainType;
public:
    TerrainTypes getTerrainType() const;

    bool IsBuildable() const;

    int getX1() const;

    int getY1() const;

    int getX2() const;

    int getY2() const;

private:
    bool isBuildable;
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
