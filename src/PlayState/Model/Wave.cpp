//
// Created by Artem on 10/5/2017.
//
#include <iostream>
#include <string>

#include "../../include/Wave.h"

Wave::Wave(int number, const std::string &successMessage, tinyxml2::XMLElement *unitsElement)
        : number(number), successMessage(successMessage) {
    for (tinyxml2::XMLElement *unit = unitsElement->FirstChildElement();
         unit != nullptr; unit = unit->NextSiblingElement()) {
        units.push_back(WaveUnits(unit->FirstChildElement("name")->GetText(),
                                  unit->FirstChildElement("description")->GetText(),
                                  std::atoi(unit->FirstChildElement("number")->GetText()),
                                  std::atoi(unit->FirstChildElement("hp")->GetText()),
                                  std::atoi(unit->FirstChildElement("size")->GetText()),
                                  std::atoi(unit->FirstChildElement("speed")->GetText()),
                                  std::atoi(unit->FirstChildElement("density")->GetText()),
                                  std::atoi(unit->FirstChildElement("id")->GetText()),
                                  std::atoi(unit->FirstChildElement("offsetx")->GetText()),
                                  std::atoi(unit->FirstChildElement("offsety")->GetText())));
    }
}

int Wave::getNumber() const {
    return number;
}

const std::string &Wave::getSuccessMessage() const {
    return successMessage;
}

const std::vector<WaveUnits> &Wave::getUnits() const {
    return units;
}
