//
// Created by Artem on 10/3/2017.
//

#include "../../include/PlayStateModel.h"

#include <iostream>
#include <fstream>

#include "../../include/Terrain.h"
#include "../../include/const.h"


PlayStateModel::PlayStateModel() {
    //create all terrain blocks
    terrainBlocks = new Terrain *[gameConstant::NUM_SQUARES_WIDE * gameConstant::NUM_SQUARES_HIGH];
    //open map file to read from
    std::ifstream mapReader;
    mapReader.open("../../config/maps/easy.map");

    if (!mapReader) {
        std::cerr << "Could not open file easy.map" << std::endl;
    } else {
        //TODO: add in checking for badly formed map files
        //generate blocks
        int i = 0;
        for (int x_pos = 0; x_pos < gameConstant::NUM_SQUARES_WIDE; x_pos++) {
            for (int y_pos = 0; y_pos < gameConstant::NUM_SQUARES_HIGH; y_pos++) {
                std::cout << "creating terrain with position " << x_pos * gameConstant::SQUARE_WIDTH << ", " << y_pos * gameConstant::SQUARE_HEIGHT << std::endl;
                std::string temp;
                mapReader >> temp;
                terrainBlocks[i] = new Terrain(x_pos * gameConstant::SQUARE_WIDTH,
                                               y_pos * gameConstant::SQUARE_HEIGHT,
                                               (x_pos + 1) * gameConstant::SQUARE_WIDTH,
                                               (y_pos + 1) * gameConstant::SQUARE_HEIGHT,
                                               getTerrainType(temp));
                i++;
            }
        }
    }
}

PlayStateModel::~PlayStateModel() {

}

void PlayStateModel::ReceiveMouseMove(int x, int y) {

}

void PlayStateModel::ReceiveMouseClick(int x, int y) {

}

void PlayStateModel::Draw() {

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
