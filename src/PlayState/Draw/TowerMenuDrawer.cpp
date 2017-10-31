//
// Created by Artem on 10/14/2017.
//

#include <iostream>
#include <sstream>
#include <string>

#include "../../include/TowerMenuDrawer.h"
#include "../../include/GameConstants.h"
#include "GraphicsConstants.h"


std::string IntToString (int a)
{
    std::ostringstream temp;
    temp<<a;
    return temp.str();
}

TowerMenuDrawer::TowerMenuDrawer(sf::RenderWindow &window) : window(window) {
    LoadTextures();
    LoadFonts();
    DefineTextFormats();
}

TowerMenuDrawer::~TowerMenuDrawer() {
}

void TowerMenuDrawer::Draw(std::vector<Tower> towers) {
    menuBackgroundSprite.setPosition(gac::WINDOW_HEIGHT, 0);
    window.draw(menuBackgroundSprite);
    for (std::vector<Tower>::iterator it = towers.begin(); it != towers.end(); ++it) {
        Tower tower = (*it);
        float basePosX = gac::WINDOW_WIDTH + grc::MENU_LEFT_MARGIN;
        float basePosY = grc::MENU_TITLE_HEIGHT + tower.getHand() * grc::MENU_DISTANCE;

        if(tower.getHand() == HIGH_CARD){
            genericTowerIconSprite.setPosition(basePosX, basePosY);
            window.draw(genericTowerIconSprite);
        }
        else{
            unknownTowerIconSprite.setPosition(basePosX, basePosY);
            window.draw(unknownTowerIconSprite);
        }
        //TODO: refactor 80s and icon size (currently 65) to constants
        nameText.setString(tower.getHandString());
        nameText.setPosition(basePosX + 80, basePosY);
        window.draw(nameText);

        damageText.setString("Damage: " + IntToString(tower.getDamage()));
        damageText.setPosition(basePosX + 80, basePosY + grc::DESC_TOP_MARGIN + grc::NAME_TEXT_SIZE);
        window.draw(damageText);

        attackSpeedText.setString("Attack Speed: " + IntToString(tower.getAttackSpeed()));
        attackSpeedText.setPosition(basePosX + 80 + grc::DESC_SIDE_OFFSET, basePosY + grc::DESC_TOP_MARGIN + grc::NAME_TEXT_SIZE);
        window.draw(attackSpeedText);

        slowAmountText.setString("Slow: " + IntToString(tower.getSlowPercent()) + "%");
        slowAmountText.setPosition(basePosX + 80, basePosY + (grc::DESC_TOP_MARGIN * 2) + grc::NAME_TEXT_SIZE + grc::DESC_TEXT_SIZE);
        window.draw(slowAmountText);

        aoeAmountText.setString("AoE: " + IntToString(tower.getAoePercent()) + "%");
        aoeAmountText.setPosition(basePosX + 80 + grc::DESC_SIDE_OFFSET, basePosY + (grc::DESC_TOP_MARGIN * 2) + grc::NAME_TEXT_SIZE + grc::DESC_TEXT_SIZE);
        window.draw(aoeAmountText);
    }
}

void TowerMenuDrawer::LoadTextures() {
    if (!menuBackgroundTexture.loadFromFile("res/img/towerMenu/menu.png")) {
        menuBackgroundTexture.create(gac::SQUARE_WIDTH_UNSIGNED, gac::SQUARE_HEIGHT_UNSIGNED);
    }
    menuBackgroundSprite.setTexture(menuBackgroundTexture);

    if (!unknownTowerIconTexture.loadFromFile("res/img/towerMenu/unknown_tower_icon_65px.png")) {
        unknownTowerIconTexture.create(gac::SQUARE_WIDTH_UNSIGNED, gac::SQUARE_HEIGHT_UNSIGNED);
    }
    unknownTowerIconSprite.setTexture(unknownTowerIconTexture);

    if (!genericTowerIconTexture.loadFromFile("res/img/towerMenu/generic_tower_icon.png")) {
        genericTowerIconTexture.create(gac::SQUARE_WIDTH_UNSIGNED, gac::SQUARE_HEIGHT_UNSIGNED);
    }
    genericTowerIconSprite.setTexture(genericTowerIconTexture);
}

void TowerMenuDrawer::LoadFonts() {
    if (!nameFont.loadFromFile("res/font/Roboto-Regular.ttf"))
    {
        std::cerr << "Could not load Roboto Regular font from res/font" << std::endl;
    }

    if (!descFont.loadFromFile("res/font/Roboto-Light.ttf"))
    {
        std::cerr << "Could not load Roboto Light font from res/font" << std::endl;
    }
}

void TowerMenuDrawer::DefineTextFormats() {
    nameText.setFont(nameFont);
    nameText.setFillColor(sf::Color::White);
    nameText.setCharacterSize(grc::NAME_TEXT_SIZE);

    damageText.setFont(descFont);
    damageText.setFillColor(sf::Color::Red);
    damageText.setCharacterSize(grc::DESC_TEXT_SIZE);

    attackSpeedText.setFont(descFont);
    attackSpeedText.setFillColor(sf::Color::Yellow);
    attackSpeedText.setCharacterSize(grc::DESC_TEXT_SIZE);

    slowAmountText.setFont(descFont);
    slowAmountText.setFillColor(sf::Color::Blue);
    slowAmountText.setCharacterSize(grc::DESC_TEXT_SIZE);

    aoeAmountText.setFont(descFont);
    aoeAmountText.setFillColor(sf::Color(255, 140, 0)); //Orange
    aoeAmountText.setCharacterSize(grc::DESC_TEXT_SIZE);
}
