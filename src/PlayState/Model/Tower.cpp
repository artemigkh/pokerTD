//
// Created by Artem on 10/15/2017.
//

#include "../../include/Tower.h"

Tower::Tower(const std::string &handString, int damage, int attackSpeed, int slowPercent, int aoePercent) :
        handString(handString), damage(damage), attackSpeed(attackSpeed), slowPercent(slowPercent), aoePercent(aoePercent) {
    if(handString == "High Card"){
        hand = HIGH_CARD;
    }
    else if(handString == "Pair"){
        hand = PAIR;
    }
    else if(handString == "Two Pair"){
        hand = TWO_PAIR;
    }
    else if(handString == "Three of a Kind"){
        hand = THREE_OF_A_KIND;
    }
    else if(handString == "Flush"){
        hand = FLUSH;
    }
    else if(handString == "Straight"){
        hand = STRAIGHT;
    }
    else if(handString == "Full House"){
        hand = FULL_HOUSE;
    }
    else if(handString == "Four of a Kind"){
        hand = FOUR_OF_A_KIND;
    }
    else if(handString == "Straight Flush"){
        hand = STRAIGHT_FLUSH;
    }
    else if(handString == "Royal Flush"){
        hand = ROYAL_FLUSH;
    }
}


const std::string &Tower::getHandString() const {
    return handString;
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

Hand Tower::getHand() const {
    return hand;
}
