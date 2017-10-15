//
// Created by Artem on 10/14/2017.
//

#include "../../include/TowerMenuDrawer.h"
#include "../../include/GameConstants.h"

TowerMenuDrawer::TowerMenuDrawer(sf::RenderWindow &window) : window(window) {
    if (!menuBackgroundTexture.loadFromFile("res/img/towerMenu/menu.png")) {
        menuBackgroundTexture.create(gac::SQUARE_WIDTH_UNSIGNED, gac::SQUARE_HEIGHT_UNSIGNED);
    }
    menuBackgroundSprite.setTexture(menuBackgroundTexture);
}

TowerMenuDrawer::~TowerMenuDrawer() {

}

void TowerMenuDrawer::Draw() {
    menuBackgroundSprite.setPosition(gac::WINDOW_HEIGHT, 0);
    window.draw(menuBackgroundSprite);
}
