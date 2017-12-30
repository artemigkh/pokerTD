//
// Created by Artem on 12/30/2017.
//

#ifndef POKERTD_ACTIVETOWERDRAWER_H
#define POKERTD_ACTIVETOWERDRAWER_H


#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "ActiveTower.h"

class ActiveTowerDrawer {
public:
    ActiveTowerDrawer(sf::RenderWindow &window);
    ~ActiveTowerDrawer();
    void Draw(std::vector<ActiveTower*> towers);

private:
    void LoadTextures();

    sf::RenderWindow& window;

    sf::Texture genericTowerTexture;
    sf::Sprite genericTowerSprite;
};


#endif //POKERTD_ACTIVETOWERDRAWER_H
