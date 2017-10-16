//
// Created by Artem on 10/15/2017.
//

#ifndef POKERTD_TOWER_H
#define POKERTD_TOWER_H

#include <string>

class Tower {
public:
    Tower(int id, const std::string &hand, int damage, int attackSpeed, int slowPercent, int aoePercent);

private:
    int id;
    std::string hand;
    int damage;
    int attackSpeed;
    int slowPercent;
    int aoePercent;
};


#endif //POKERTD_TOWER_H
