//
// Created by Artem on 10/5/2017.
//

#include "../../include/WaveUnits.h"

WaveUnits::WaveUnits(const std::string &name, const std::string &description, int number, int hp, int size, int speed,
                     int density, int id, int xOffset, int yOffset) : name(name), description(description),
                                                                      number(number), hp(hp), size(size), speed(speed),
                                                                      density(density), id(id), xOffset(xOffset),
                                                                      yOffset(yOffset) {}
