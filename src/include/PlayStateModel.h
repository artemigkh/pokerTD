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
#include "Unit.h"
#include "Tower.h"

class Unit;
class PlayStateDrawObject;

class PlayStateModel {
public:
    PlayStateModel();
    ~PlayStateModel();
    void ReceiveMouseMove(int x, int y);
    void ReceiveMouseClick(int x, int y);
    void Draw(PlayStateDrawObject *drawObject);
    void Update();
    const std::vector<Terrain> &getTerrainBlocks() const;

private:
    bool towerPlaceState;
    Hand towerBeingPlaced;
    int mousePosX;
    int mousePosY;

    void LoadTerrain();
    void LoadWaveInformation();
    void LoadTowerInformation();
    void StartWave(int waveNumber);

    void CheckMenuItems(int x, int y);
    TerrainTypes getTerrainType(std::string sample);

    std::vector<Unit> units;
    std::vector<Terrain> terrainBlocks;
    std::vector<Wave> waves;
    std::vector<Tower> availableTowers;
    std::vector<ActiveTower> activeTowers;

    void MoveUnits();
    void CheckTowerBuilding();
};


#endif //POKERTD_PLAYSTATEMODEL_H
