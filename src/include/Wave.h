//
// Created by Artem on 10/5/2017.
//

#ifndef POKERTD_WAVE_H
#define POKERTD_WAVE_H

#include <string>
#include <vector>
#include "../../lib/tinyxml2.h"

#include "WaveUnits.h"

class Wave {
public:
    Wave(int number, const std::string &successMessage, tinyxml2::XMLElement* unitsElement);

private:
    int number;
    std::string successMessage;
    std::vector<WaveUnits> units;
};


#endif //POKERTD_WAVE_H
