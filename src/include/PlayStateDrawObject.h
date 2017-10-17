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
#include "Unit.h"
#include "TowerMenuDrawer.h"
//TODO: refactor terrain part into a terrain drawer class

class PlayStateDrawObject {
public:
    PlayStateDrawObject(sf::RenderWindow &window);
    ~PlayStateDrawObject();
    void DrawTerrain(std::vector<Terrain> terrainBlocks);
    void DrawUnits(std::vector<Unit> units);
    void DrawTowerMenu(std::vector<Tower> menuTowers);

private:
    void LoadTerrainTextures();
    void CreateUnitDrawers();

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
    TowerMenuDrawer towerMenuDrawer;
};


#endif //POKERTD_PLAYSTATEDRAWOBJECT_H
