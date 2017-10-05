//
// Created by Artem on 10/3/2017.
//

#include "../../include/PlayStateModel.h"

#include <iostream>
#include <fstream>

#include "../../include/Terrain.h"
#include "../../include/const.h"
#include "../../include/PlayStateDrawObject.h"

PlayStateModel::PlayStateModel() {
    //open map file to read from
    std::ifstream mapReader;
    mapReader.open("config/maps/easy.map");

    //read in terrain from file
    if (mapReader.fail()) {
        std::cerr << "Could not open file easy.map" << std::endl;
    } else {
        //TODO: add in checking for badly formed map files
        //generate blocks
        int i = 0;
        for (int y_pos = 0; y_pos < gameConstant::NUM_SQUARES_WIDE; y_pos++) {
            for (int x_pos = 0; x_pos < gameConstant::NUM_SQUARES_HIGH; x_pos++) {
                std::string temp;
                mapReader >> temp;
                terrainBlocks.push_back(new Terrain(x_pos * gameConstant::SQUARE_WIDTH,
                                               y_pos * gameConstant::SQUARE_HEIGHT,
                                               (x_pos + 1) * gameConstant::SQUARE_WIDTH,
                                               (y_pos + 1) * gameConstant::SQUARE_HEIGHT,
                                               getTerrainType(temp)));
                i++;
            }
        }
    }
}

PlayStateModel::~PlayStateModel() {
    while (!terrainBlocks.empty()) {
        delete terrainBlocks.back();
        terrainBlocks.pop_back();
    }
}

void PlayStateModel::ReceiveMouseMove(int x, int y) {

}

void PlayStateModel::ReceiveMouseClick(int x, int y) {

}

void PlayStateModel::Draw(PlayStateDrawObject *pObject) {
    pObject->DrawTerrain(terrainBlocks);
}

TerrainTypes PlayStateModel::getTerrainType(std::string sample) {
    if(sample == "tl"){
        return CORNER_TOP_LEFT;
    }
    else if(sample == "tr"){
        return CORNER_TOP_RIGHT;
    }
    else if(sample == "bl"){
        return CORNER_BOTTOM_LEFT;
    }
    else if(sample == "br"){
        return CORNER_BOTTOM_RIGHT;
    }
    else if(sample == "-"){
        return HORIZONTAL;
    }
    else if(sample == "|"){
        return VERTICAL;
    }
    else if(sample == "g"){
        return BUILDABLE;
    }
    else{
        return UNDEFINED;
    }
}
