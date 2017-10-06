//
// Created by Artem on 10/3/2017.
//

#ifndef POKERTD_PLAYSTATEMODEL_H
#define POKERTD_PLAYSTATEMODEL_H

#include <vector>
#include <string>

#include "../PlayState/TerrainTypes.h"
#include "PlayStateDrawObject.h"
#include "Terrain.h"
#include "Wave.h"

class Terrain;

class PlayStateModel {
public:
    PlayStateModel();
    ~PlayStateModel();
    void ReceiveMouseMove(int x, int y);
    void ReceiveMouseClick(int x, int y);
    void Draw(PlayStateDrawObject *pObject);

private:
    void LoadTerrain();
    void LoadWaveInformation();

    TerrainTypes getTerrainType(std::string sample);
    std::vector<Terrain> terrainBlocks;
    std::vector<Wave> waves;
};


#endif //POKERTD_PLAYSTATEMODEL_H
