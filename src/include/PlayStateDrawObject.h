//
// Created by Artem on 10/3/2017.
//

#ifndef POKERTD_PLAYSTATEDRAWOBJECT_H
#define POKERTD_PLAYSTATEDRAWOBJECT_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "../include/Terrain.h"


class PlayStateDrawObject {
public:
    PlayStateDrawObject(sf::RenderWindow &window);

    void DrawTerrain(Terrain** terrainBlocks);

private:
    sf::RenderWindow& window;
};


#endif //POKERTD_PLAYSTATEDRAWOBJECT_H
