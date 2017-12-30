//
// Created by Artem on 10/29/2017.
//

#include "../../include/ActiveTower.h"

ActiveTower::ActiveTower(const Tower &baseTower, int posX, int posY) : Tower(baseTower), posX(posX), posY(posY){

}

int ActiveTower::getPosX() const {
    return posX;
}

int ActiveTower::getPosY() const {
    return posY;
}
