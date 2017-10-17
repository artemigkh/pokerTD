//
// Created by Artem on 10/15/2017.
//

#include "../../include/Tower.h"

Tower::Tower(int id, const std::string &hand, int damage, int attackSpeed, int slowPercent, int aoePercent) :
        id(id), hand(hand), damage(damage), attackSpeed(attackSpeed), slowPercent(slowPercent), aoePercent(aoePercent) {

}

int Tower::getId() const {
    return id;
}

const std::string &Tower::getHand() const {
    return hand;
}

int Tower::getDamage() const {
    return damage;
}

int Tower::getAttackSpeed() const {
    return attackSpeed;
}

int Tower::getSlowPercent() const {
    return slowPercent;
}

int Tower::getAoePercent() const {
    return aoePercent;
}