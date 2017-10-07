//
// Created by Artem on 10/3/2017.
//

#ifndef POKERTD_PLAYSTATEDRAWOBJECT_H
#define POKERTD_PLAYSTATEDRAWOBJECT_H

#include <vector>
#include <map>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "../include/Terrain.h"
#include "SpriteDrawObject.h"


class PlayStateDrawObject {
public:
    PlayStateDrawObject(sf::RenderWindow &window);
    ~PlayStateDrawObject();
    void DrawTerrain(std::vector<Terrain> terrainBlocks);

private:
    void LoadTerrainTextures();
    void LoadUnitSpriteSheets();

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

    std::map<int, SpriteDrawObject*> unitDrawers;
};


#endif //POKERTD_PLAYSTATEDRAWOBJECT_H
