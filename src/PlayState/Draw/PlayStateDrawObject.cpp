//
// Created by Artem on 10/3/2017.
//

#include "../../include/PlayStateDrawObject.h"

#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include "../../../lib/tinyxml2.h"

#include "../TerrainTypes.h"
#include "../../include/GameConstants.h"

PlayStateDrawObject::PlayStateDrawObject(sf::RenderWindow &window) : window(window), towerMenuDrawer(window), activeTowerDrawer(window) {
    LoadTerrainTextures();
    CreateUnitDrawers();
}

void PlayStateDrawObject::DrawTerrain(std::vector<Terrain> terrainBlocks) {
    //TODO: refactor this into its own class
    //iterate through every terrain block
    for (std::vector<Terrain>::iterator it = terrainBlocks.begin(); it != terrainBlocks.end(); ++it) {
        Terrain t = (*it);
        //TODO: refactor into something that handles states more cleanly
        switch (t.getTerrainType()) {
            case CORNER_TOP_LEFT:
                cornerTopLeftTerrainSprite.setPosition(t.getX1(), t.getY1());
                window.draw(cornerTopLeftTerrainSprite);
                break;
            case CORNER_TOP_RIGHT:
                cornerTopRightTerrainSprite.setPosition(t.getX1(), t.getY1());
                window.draw(cornerTopRightTerrainSprite);
                break;
            case CORNER_BOTTOM_LEFT:
                cornerBottomLeftTerrainSprite.setPosition(t.getX1(), t.getY1());
                window.draw(cornerBottomLeftTerrainSprite);
                break;
            case CORNER_BOTTOM_RIGHT:
                cornerBottomRightTerrainSprite.setPosition(t.getX1(), t.getY1());
                window.draw(cornerBottomRightTerrainSprite);
                break;
            case VERTICAL:
                verticalTerrainSprite.setPosition(t.getX1(), t.getY1());
                window.draw(verticalTerrainSprite);
                break;
            case HORIZONTAL:
                horizontalTerrainSprite.setPosition(t.getX1(), t.getY1());
                window.draw(horizontalTerrainSprite);
                break;
            case BUILDABLE:
                if(t.IsValidBuildState()){
                    buildableTerrainSprite.setColor(sf::Color(0, 255, 0, 128));
                }
                buildableTerrainSprite.setPosition(t.getX1(), t.getY1());
                window.draw(buildableTerrainSprite);
                buildableTerrainSprite.setColor(sf::Color(255, 255, 255, 255));
                break;
            default:
                undefinedTerrainSprite.setPosition(t.getX1(), t.getY1());
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
             spriteSheet != nullptr; spriteSheet = spriteSheet->NextSiblingElement()) {
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

void PlayStateDrawObject::DrawActiveTowers(std::vector<ActiveTower*> activeTowers) {
    activeTowerDrawer.Draw(activeTowers);
}

