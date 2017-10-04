//
// Created by Artem on 10/3/2017.
//

#ifndef POKERTD_TERRAIN_H
#define POKERTD_TERRAIN_H

#include "../PlayState/TerrainTypes.h"

class Terrain {
public:
    Terrain(int x1, int y1, int y2, int x2, TerrainTypes terrainType);

private:
    TerrainTypes terrainType;
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
