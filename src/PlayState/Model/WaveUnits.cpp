//
// Created by Artem on 10/5/2017.
//

#include "../../include/WaveUnits.h"

WaveUnits::WaveUnits(const std::string &name, const std::string &description, int number, int hp, int size, int speed,
                     int density, int id, int xOffset, int yOffset) : name(name), description(description),
                                                                      number(number), hp(hp), size(size), speed(speed),
                                                                      density(density), id(id), xOffset(xOffset),
                                                                      yOffset(yOffset) {}

const std::string &WaveUnits::getName() const {
    return name;
}

const std::string &WaveUnits::getDescription() const {
    return description;
}

int WaveUnits::getNumber() const {
    return number;
}

int WaveUnits::getHp() const {
    return hp;
}

int WaveUnits::getSize() const {
    return size;
}

int WaveUnits::getSpeed() const {
    return speed;
}

int WaveUnits::getDensity() const {
    return density;
}

int WaveUnits::getId() const {
    return id;
}

int WaveUnits::getXOffset() const {
    return xOffset;
}

int WaveUnits::getYOffset() const {
    return yOffset;
}
