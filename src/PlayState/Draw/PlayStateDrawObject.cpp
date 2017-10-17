//
// Created by Artem on 10/3/2017.
//

#include "../../include/PlayStateDrawObject.h"

#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include "../../../lib/tinyxml2.h"

#include "../TerrainTypes.h"
#include "../../include/GameConstants.h"

PlayStateDrawObject::PlayStateDrawObject(sf::RenderWindow &window) : window(window), towerMenuDrawer(window) {
    LoadTerrainTextures();
    CreateUnitDrawers();
}

void PlayStateDrawObject::DrawTerrain(std::vector<Terrain> terrainBlocks) {

    //iterate through every terrain block
    for (std::vector<Terrain>::iterator it = terrainBlocks.begin(); it != terrainBlocks.end(); ++it) {
        switch ((*it).getTerrainType()) {
            case CORNER_TOP_LEFT:
                cornerTopLeftTerrainSprite.setPosition((*it).getX1(), (*it).getY1());
                window.draw(cornerTopLeftTerrainSprite);
                break;
            case CORNER_TOP_RIGHT:
                cornerTopRightTerrainSprite.setPosition((*it).getX1(), (*it).getY1());
                window.draw(cornerTopRightTerrainSprite);
                break;
            case CORNER_BOTTOM_LEFT:
                cornerBottomLeftTerrainSprite.setPosition((*it).getX1(), (*it).getY1());
                window.draw(cornerBottomLeftTerrainSprite);
                break;
            case CORNER_BOTTOM_RIGHT:
                cornerBottomRightTerrainSprite.setPosition((*it).getX1(), (*it).getY1());
                window.draw(cornerBottomRightTerrainSprite);
                break;
            case VERTICAL:
                verticalTerrainSprite.setPosition((*it).getX1(), (*it).getY1());
                window.draw(verticalTerrainSprite);
                break;
            case HORIZONTAL:
                horizontalTerrainSprite.setPosition((*it).getX1(), (*it).getY1());
                window.draw(horizontalTerrainSprite);
                break;
            case BUILDABLE:
                buildableTerrainSprite.setPosition((*it).getX1(), (*it).getY1());
                window.draw(buildableTerrainSprite);
                break;
            default:
                undefinedTerrainSprite.setPosition((*it).getX1(), (*it).getY1());
                window.draw(undefinedTerrainSprite);
                break;
        }
    }
}

void PlayStateDrawObject::LoadTerrainTextures() {
    //load textures and create sprites
    if (!buildableTexture.loadFromFile("res/img/terrain/buildable.png")) {
        buildableTexture.create(gac::SQUARE_WIDTH_UNSIGNED, gac::SQUARE_HEIGHT_UNSIGNED);
    }
    buildableTerrainSprite.setTexture(buildableTexture);

    if (!cornerTexture.loadFromFile("res/img/terrain/corners_12.png")) {
        cornerTexture.create(gac::SQUARE_WIDTH_UNSIGNED, gac::SQUARE_HEIGHT_UNSIGNED);
    }
    //TODO: Use constants instead of hard coding in values
    cornerTopRightTerrainSprite.setTexture(cornerTexture);
    cornerTopRightTerrainSprite.setTextureRect(sf::IntRect(0, 0, 125, 125));
    cornerBottomRightTerrainSprite.setTexture(cornerTexture);
    cornerBottomRightTerrainSprite.setTextureRect(sf::IntRect(125, 0, 125, 125));
    cornerBottomLeftTerrainSprite.setTexture(cornerTexture);
    cornerBottomLeftTerrainSprite.setTextureRect(sf::IntRect(250, 0, 125, 125));
    cornerTopLeftTerrainSprite.setTexture(cornerTexture);
    cornerTopLeftTerrainSprite.setTextureRect(sf::IntRect(375, 0, 125, 125));

    if (!straightTexture.loadFromFile("res/img/terrain/straights_12.png")) {
        straightTexture.create(gac::SQUARE_WIDTH_UNSIGNED, gac::SQUARE_HEIGHT_UNSIGNED);
    }
    verticalTerrainSprite.setTexture(straightTexture);
    verticalTerrainSprite.setTextureRect(sf::IntRect(0, 0, 125, 125));
    horizontalTerrainSprite.setTexture(straightTexture);
    horizontalTerrainSprite.setTextureRect(sf::IntRect(125, 0, 125, 125));

    undefinedTexture.create(gac::SQUARE_WIDTH_UNSIGNED, gac::SQUARE_HEIGHT_UNSIGNED);
    undefinedTerrainSprite.setTexture(undefinedTexture);
}

void PlayStateDrawObject::CreateUnitDrawers() {
    //TODO: dont crash on invalid xml
    tinyxml2::XMLDocument doc;
    if (doc.LoadFile("config/graphics/sprite_sheets.xml")) {
        std::cerr << "Could not load file sprite_sheets.xml" << std::endl;
    } else {
        tinyxml2::XMLElement *spriteSheetsElement = doc.FirstChildElement("spriteSheets");
        for (tinyxml2::XMLElement *spriteSheet = spriteSheetsElement->FirstChildElement();
             spriteSheet != NULL; spriteSheet = spriteSheet->NextSiblingElement()) {
            //do this for every wave:
            unitDrawers[std::atoi(spriteSheet->FirstChildElement("id")->GetText())] =
                    new SpriteDrawObject(window, spriteSheet->FirstChildElement("filename")->GetText());
        }
    }
}

PlayStateDrawObject::~PlayStateDrawObject() {
    //TODO: delete pointers in unitDrawers
}

void PlayStateDrawObject::DrawUnits(std::vector<Unit> units) {
    for (std::vector<Unit>::iterator it = units.begin(); it != units.end(); ++it) {
        Unit unit = (*it);
        unitDrawers[unit.getSpriteSheetID()]->Draw(unit.getCurrPosX(),
                                                   unit.getCurrPosY(),
                                                   unit.getSize(),
                                                   unit.getSize(),
                                                   unit.getSpriteSheetOffsetX(),
                                                   unit.getSpriteSheetOffsetY(),
                                                   unit.getFramePos(),
                                                   unit.getOrientation()
        );
    }
}

void PlayStateDrawObject::DrawTowerMenu(std::vector<Tower> menuTowers) {
    towerMenuDrawer.Draw(menuTowers);
}

