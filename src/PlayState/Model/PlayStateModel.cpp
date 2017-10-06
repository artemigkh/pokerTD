//
// Created by Artem on 10/3/2017.
//

#include "../../include/PlayStateModel.h"

#include <iostream>
#include <fstream>
#include <string>

#include "../../../lib/tinyxml2.h"

#include "../../include/const.h"
#include "../../include/PlayStateDrawObject.h"

PlayStateModel::PlayStateModel() {
    LoadTerrain();
    LoadWaveInformation();
}

PlayStateModel::~PlayStateModel() {
}

void PlayStateModel::ReceiveMouseMove(int x, int y) {

}

void PlayStateModel::ReceiveMouseClick(int x, int y) {

}

void PlayStateModel::Draw(PlayStateDrawObject *pObject) {
    pObject->DrawTerrain(terrainBlocks);
}

TerrainTypes PlayStateModel::getTerrainType(std::string sample) {
    if (sample == "tl") {
        return CORNER_TOP_LEFT;
    } else if (sample == "tr") {
        return CORNER_TOP_RIGHT;
    } else if (sample == "bl") {
        return CORNER_BOTTOM_LEFT;
    } else if (sample == "br") {
        return CORNER_BOTTOM_RIGHT;
    } else if (sample == "-") {
        return HORIZONTAL;
    } else if (sample == "|") {
        return VERTICAL;
    } else if (sample == "g") {
        return BUILDABLE;
    } else {
        return UNDEFINED;
    }
}

void PlayStateModel::LoadTerrain() {
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
                terrainBlocks.push_back(Terrain(x_pos * gameConstant::SQUARE_WIDTH,
                                                y_pos * gameConstant::SQUARE_HEIGHT,
                                                (x_pos + 1) * gameConstant::SQUARE_WIDTH,
                                                (y_pos + 1) * gameConstant::SQUARE_HEIGHT,
                                                getTerrainType(temp)));
                i++;
            }
        }
    }
}

void PlayStateModel::LoadWaveInformation() {
    //TODO: dont crash on invalid xml
    tinyxml2::XMLDocument doc;
    if (doc.LoadFile("config/levels/easy.xml")) {
        std::cerr << "Could not load file easy.xml" << std::endl;
    } else {
        tinyxml2::XMLElement *wavesElement = doc.FirstChildElement("waves");
        for (tinyxml2::XMLElement *wave = wavesElement->FirstChildElement();
             wave != NULL; wave = wave->NextSiblingElement()) {
            //do this for every wave:
            waves.push_back(Wave(std::atoi(wave->FirstChildElement("number")->GetText()),
                                 wave->FirstChildElement("successMessage")->GetText(),
                                 wave->FirstChildElement("units")));
        }
    }
}
