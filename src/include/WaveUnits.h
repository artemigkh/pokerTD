//
// Created by Artem on 10/5/2017.
//

#ifndef POKERTD_WAVEUNITS_H
#define POKERTD_WAVEUNITS_H

#include <string>

class WaveUnits {
public:
    WaveUnits(const std::string &name, const std::string &description, int number, int hp, int size, int speed,
              int density, int id, int xOffset, int yOffset);

private:
    std::string name;
    std::string description;
    int number;
    int hp;
    int size;
    int speed;
    int density;
    int id;
    int xOffset;
    int yOffset;
};


#endif //POKERTD_WAVEUNITS_H