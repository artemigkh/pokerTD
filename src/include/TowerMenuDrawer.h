//
// Created by Artem on 10/14/2017.
//

#ifndef POKERTD_TOWERMENUDRAWER_H
#define POKERTD_TOWERMENUDRAWER_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Tower.h"

class TowerMenuDrawer {
public:
    TowerMenuDrawer(sf::RenderWindow &window);
    ~TowerMenuDrawer();
    void Draw(std::vector<Tower> towers);

private:
    sf::RenderWindow& window;

    sf::Texture menuBackgroundTexture;
    sf::Sprite menuBackgroundSprite;

    sf::Texture unknownTowerIconTexture;
    sf::Sprite unknownTowerIconSprite;
};


#endif //POKERTD_TOWERMENUDRAWER_H
