//
// Created by Artem on 10/14/2017.
//

#ifndef POKERTD_TOWERMENUDRAWER_H
#define POKERTD_TOWERMENUDRAWER_H


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class TowerMenuDrawer {
public:
    TowerMenuDrawer(sf::RenderWindow &window);
    ~TowerMenuDrawer();
    void Draw();

private:
    sf::RenderWindow& window;

    sf::Texture menuBackgroundTexture;
    sf::Sprite menuBackgroundSprite;

    sf::Texture unknownTowerIcon;
    sf::Sprite unknownTowerSprite;
};


#endif //POKERTD_TOWERMENUDRAWER_H
