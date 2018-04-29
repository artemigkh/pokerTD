//
// Created by Artem on 10/7/2017.
//

#include <iostream>
#include "../../include/PlayStateModel.h"
#include "../../include/Unit.h"
#include "../../include/GameConstants.h"
#include "../Draw/GraphicsConstants.h"
#include "../../include/PlayStateModel.h"

void Unit::Update(PlayStateModel *playStateModel) {
    //move the units position and change the orientation if it passes threshold
    switch (orientation) {
        case 0: //down
            currPosY += tickMoveSpeed;
            if (currPosY > (gac::SQUARE_HEIGHT_FLOAT * ((float) terrainY + 1)) + (gac::SQUARE_HEIGHT_FLOAT / 2 - (float)size / 2)) {
                terrainY++;
                orientation = getNewDirection(playStateModel->getTerrainBlocks()[terrainX + terrainY * gac::NUM_SQUARES_WIDE].getTerrainType(), orientation);
            }
            break;
        case 1: // left
            currPosX -= tickMoveSpeed;
            if (currPosX < (gac::SQUARE_WIDTH_FLOAT * ((float) terrainX - 1)) + (gac::SQUARE_WIDTH_FLOAT / 2)) {
                terrainX--;
                orientation = getNewDirection(playStateModel->getTerrainBlocks()[terrainX + terrainY * gac::NUM_SQUARES_WIDE].getTerrainType(), orientation);
            }
            break;
        case 2: //right
            currPosX += tickMoveSpeed;
            if (currPosX > (gac::SQUARE_WIDTH_FLOAT * ((float) terrainX + 1)) + (gac::SQUARE_WIDTH_FLOAT / 2)) {
                terrainX++;
                orientation = getNewDirection(playStateModel->getTerrainBlocks()[terrainX + terrainY * gac::NUM_SQUARES_WIDE].getTerrainType(), orientation);
            }
            break;
        case 3: //top
            currPosY -= tickMoveSpeed;
            if (currPosY < (gac::SQUARE_HEIGHT_FLOAT * ((float) terrainY - 1)) + (gac::SQUARE_HEIGHT_FLOAT / 2 - (float)size / 2)) {
                terrainY--;
                orientation = getNewDirection(playStateModel->getTerrainBlocks()[terrainX + terrainY * gac::NUM_SQUARES_WIDE].getTerrainType(), orientation);
            }
            break;
        default:
            break;
    }
    //handle changing of unit frame
    framePosCounter++;
    if (framePosCounter >= grc::NUM_TICKS_IN_SPRITE_FRAME) {
        framePosCounter = 0;
        if (framePos == 2) {
            framePos = 0;
        } else {
            framePos++;
        }
    }
}

const std::string &Unit::getName() const {
    return name;
}

const std::string &Unit::getDescription() const {
    return description;
}

int Unit::getCurrHP() const {
    return currHP;
}

int Unit::getOrientation() const {
    return orientation;
}

int Unit::getFramePos() const {
    return framePos;
}

int Unit::getSpriteSheetID() const {
    return spriteSheetID;
}

int Unit::getSpriteSheetOffsetX() const {
    return spriteSheetOffsetX;
}

int Unit::getSpriteSheetOffsetY() const {
    return spriteSheetOffsetY;
}

float Unit::getCurrPosX() const {
    return currPosX;
}

int Unit::getSize() const {
    return size;
}


float Unit::getCurrPosY() const {
    return currPosY;
}

int Unit::getNewDirection(TerrainTypes terrain, int orientation) {
    switch (terrain) {
        case CORNER_TOP_LEFT:
            if(orientation == 3){
                return 2;
            }
            else if(orientation == 1){
                return 0;
            }
            else{
                return orientation;
            }
        case CORNER_TOP_RIGHT:
            if(orientation == 2){
                return 0;
            }
            else if(orientation == 3){
                return 1;
            }
            else{
                return orientation;
            }
        case CORNER_BOTTOM_LEFT:
            if(orientation == 0){
                return 2;
            }
            else if(orientation == 1){
                return 3;
            }
            else{
                return orientation;
            }
        case CORNER_BOTTOM_RIGHT:
            if(orientation == 2){
                return 3;
            }
            else if(orientation == 0){
                return 1;
            }
            else{
                return orientation;
            }
        case VERTICAL:
            if(orientation == 0){
                return 0;
            }
            else if(orientation == 3){
                return 3;
            }
            else{
                return orientation;
            }
        case HORIZONTAL:
            if(orientation == 1){
                return 1;
            }
            else if(orientation == 2){
                return 2;
            }
            else{
                return orientation;
            }
        default:
            return orientation;
    }
}

Unit::Unit(const std::string &name, const std::string &description, int currHP, int size, int speed, float currPosX,
           float currPosY, int terrainX, int terrainY, int orientation, int spriteSheetID, int spriteSheetOffsetX,
           int spriteSheetOffsetY)
        : name(name), description(description), currHP(currHP), maxHP(currHP), size(size), speed(speed),
          currPosX(currPosX), currPosY(currPosY), terrainX(terrainX), terrainY(terrainY),
          orientation(orientation), spriteSheetID(spriteSheetID),
          spriteSheetOffsetX(spriteSheetOffsetX), spriteSheetOffsetY(spriteSheetOffsetY) {
    framePosCounter = 0;
    framePos = 0;
    tickMoveSpeed = speed / gac::FRAMES_PER_SECOND;
}

float Unit::getHealthPercent() {
    return (float)currHP / (float)maxHP;
}



