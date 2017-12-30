//
// Created by Artem on 10/29/2017.
//

#ifndef POKERTD_ACTIVETOWER_H
#define POKERTD_ACTIVETOWER_H


#include "Tower.h"

class ActiveTower : public Tower{
public:
    ActiveTower(const Tower &baseTower, int posX, int posY);

private:
    int posX;
    int posY;
public:
    int getPosX() const;

    int getPosY() const;
};


#endif //POKERTD_ACTIVETOWER_H
