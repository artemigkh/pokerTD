//
// Created by Artem on 10/14/2017.
//

#include <iostream>
#include "../../include/TowerMenuDrawer.h"
#include "../../include/GameConstants.h"
#include "GraphicsConstants.h"

TowerMenuDrawer::TowerMenuDrawer(sf::RenderWindow &window) : window(window) {
    if (!menuBackgroundTexture.loadFromFile("res/img/towerMenu/menu.png")) {
        menuBackgroundTexture.create(gac::SQUARE_WIDTH_UNSIGNED, gac::SQUARE_HEIGHT_UNSIGNED);
    }
    menuBackgroundSprite.setTexture(menuBackgroundTexture);

    if (!unknownTowerIconTexture.loadFromFile("res/img/towerMenu/unknown_tower_icon_65px.png")) {
        unknownTowerIconTexture.create(gac::SQUARE_WIDTH_UNSIGNED, gac::SQUARE_HEIGHT_UNSIGNED);
    }
    unknownTowerIconSprite.setTexture(unknownTowerIconTexture);

}

TowerMenuDrawer::~TowerMenuDrawer() {
}

void TowerMenuDrawer::Draw(std::vector<Tower> towers) {
    menuBackgroundSprite.setPosition(gac::WINDOW_HEIGHT, 0);
    window.draw(menuBackgroundSprite);
    for (std::vector<Tower>::iterator it = towers.begin(); it != towers.end(); ++it) {
        Tower tower = (*it);
        unknownTowerIconSprite.setPosition(gac::WINDOW_WIDTH + grc::MENU_LEFT_MARGIN, grc::MENU_TITLE_HEIGHT + tower.getId() * grc::MENU_DISTANCE);
        window.draw(unknownTowerIconSprite);
    }
}
