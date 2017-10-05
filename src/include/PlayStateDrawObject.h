//
// Created by Artem on 10/3/2017.
//

#ifndef POKERTD_PLAYSTATEDRAWOBJECT_H
#define POKERTD_PLAYSTATEDRAWOBJECT_H

#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "../include/Terrain.h"


class PlayStateDrawObject {
public:
    PlayStateDrawObject(sf::RenderWindow &window);

    void DrawTerrain(std::vector<Terrain *> terrainBlocks);

private:
    sf::RenderWindow& window;

    sf::Texture buildableTexture;
    sf::Sprite buildableTerrainSprite;

    sf::Texture straightTexture;
    sf::Sprite verticalTerrainSprite;
    sf::Sprite horizontalTerrainSprite;

    sf::Texture cornerTexture;
    sf::Sprite cornerTopLeftTerrainSprite;
    sf::Sprite cornerTopRightTerrainSprite;
    sf::Sprite cornerBottomLeftTerrainSprite;
    sf::Sprite cornerBottomRightTerrainSprite;

    sf::Texture undefinedTexture;
    sf::Sprite undefinedTerrainSprite;
};


#endif //POKERTD_PLAYSTATEDRAWOBJECT_H
