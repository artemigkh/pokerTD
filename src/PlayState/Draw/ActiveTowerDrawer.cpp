//
// Created by Artem on 12/30/2017.
//

#include "../../include/ActiveTowerDrawer.h"
#include "../../include/GameConstants.h"

ActiveTowerDrawer::ActiveTowerDrawer(sf::RenderWindow &window) : window(window)  {
    LoadTextures();
}

ActiveTowerDrawer::~ActiveTowerDrawer() {

}

void ActiveTowerDrawer::Draw(std::vector<ActiveTower *> towers) {
    for (std::vector<ActiveTower*>::iterator it = towers.begin(); it != towers.end(); ++it) {
        ActiveTower *t = (*it);
        //TODO: proper centering of towers, and top and bottom seperate elements
        genericTowerSprite.setPosition(t->getPosX() + 30, t->getPosY() + 30);
        window.draw(genericTowerSprite);
    }
}

void ActiveTowerDrawer::LoadTextures() {
    if (!genericTowerTexture.loadFromFile("res/img/towers/generic_tower.png")) {
        genericTowerTexture.create(gac::SQUARE_WIDTH_UNSIGNED, gac::SQUARE_HEIGHT_UNSIGNED);
    }
    genericTowerSprite.setTexture(genericTowerTexture);
}
