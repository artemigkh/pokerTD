//
// Created by Artem on 10/15/2017.
//

#ifndef POKERTD_TOWER_H
#define POKERTD_TOWER_H

#include <string>
#include "../PlayState/HandsEnum.h"

class Tower {
public:
    Tower(const std::string &hand, int damage, int attackSpeed, int slowPercent, int aoePercent);
    Tower(const Tower &oTower);

    const std::string &getHandString() const;

    int getDamage() const;

    int getAttackSpeed() const;

    int getSlowPercent() const;

    int getAoePercent() const;

private:
    Hand hand;
public:
    Hand getHand() const;

private:
    std::string handString;
    int damage;
    int attackSpeed;
    int slowPercent;
    int aoePercent;
};


#endif //POKERTD_TOWER_H
