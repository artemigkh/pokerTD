//
// Created by Artem on 10/7/2017.
//

#include "../../include/Unit.h"
#include "../../include/GameConstants.h"
#include "../Draw/GraphicsConstants.h"

void Unit::Update() {
    //move the units position
    switch (orientation) {
        case 0: //down
            currPosY -= tickMoveSpeed;
            break;
        case 1: // left
            currPosX -= tickMoveSpeed;
            break;
        case 2: //right
            currPosX += tickMoveSpeed;
            break;
        case 3: //top
            currPosY += tickMoveSpeed;
            break;
        default:
            break;
    }
    //handle changing of unit frame
    framePosCounter++;
    if(framePosCounter >= grc::NUM_TICKS_IN_SPRITE_FRAME){
        framePosCounter = 0;
        if(framePos == 2){
            framePos = 0;
        }
        else{
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

Unit::Unit(const std::string &name, const std::string &description, int currHP, int size, int speed, float currPosX,
           float currPosY, int orientation, int spriteSheetID, int spriteSheetOffsetX, int spriteSheetOffsetY) : name(
        name), description(description), currHP(currHP), size(size), speed(speed), currPosX(currPosX), currPosY(
        currPosY), orientation(orientation), spriteSheetID(spriteSheetID), spriteSheetOffsetX(spriteSheetOffsetX),
        spriteSheetOffsetY(spriteSheetOffsetY) {
    tickMoveSpeed = speed / gac::FRAMES_PER_SECOND;
    framePos = 0;
    framePosCounter = 0;
}


