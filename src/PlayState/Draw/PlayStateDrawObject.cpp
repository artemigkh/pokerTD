//
// Created by Artem on 10/3/2017.
//

#include "../../include/PlayStateDrawObject.h"

#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>

#include "../TerrainTypes.h"
#include "../../include/const.h"

PlayStateDrawObject::PlayStateDrawObject(sf::RenderWindow &window) : window(window) {
    //load textures and create sprites
    if (!buildableTexture.loadFromFile("res/img/terrain/buildable.png")) {
        buildableTexture.create(gameConstant::SQUARE_WIDTH_UNSIGNED, gameConstant::SQUARE_HEIGHT_UNSIGNED);
    }
    buildableTerrainSprite.setTexture(buildableTexture);

    if (!cornerTexture.loadFromFile("res/img/terrain/corners_12.png")) {
        cornerTexture.create(gameConstant::SQUARE_WIDTH_UNSIGNED, gameConstant::SQUARE_HEIGHT_UNSIGNED);
    }
    cornerTopRightTerrainSprite.setTexture(cornerTexture);
    cornerTopRightTerrainSprite.setTextureRect(sf::IntRect(0, 0, 125, 125));
    cornerBottomRightTerrainSprite.setTexture(cornerTexture);
    cornerBottomRightTerrainSprite.setTextureRect(sf::IntRect(125, 0, 125, 125));
    cornerBottomLeftTerrainSprite.setTexture(cornerTexture);
    cornerBottomLeftTerrainSprite.setTextureRect(sf::IntRect(250, 0, 125, 125));
    cornerTopLeftTerrainSprite.setTexture(cornerTexture);
    cornerTopLeftTerrainSprite.setTextureRect(sf::IntRect(375, 0, 125, 125));

    if (!straightTexture.loadFromFile("res/img/terrain/straights_12.png")) {
        straightTexture.create(gameConstant::SQUARE_WIDTH_UNSIGNED, gameConstant::SQUARE_HEIGHT_UNSIGNED);
    }
    verticalTerrainSprite.setTexture(straightTexture);
    verticalTerrainSprite.setTextureRect(sf::IntRect(0, 0, 125, 125));
    horizontalTerrainSprite.setTexture(straightTexture);
    horizontalTerrainSprite.setTextureRect(sf::IntRect(125, 0, 125, 125));

    undefinedTexture.create(gameConstant::SQUARE_WIDTH_UNSIGNED, gameConstant::SQUARE_HEIGHT_UNSIGNED);
    undefinedTerrainSprite.setTexture(undefinedTexture);
}

void PlayStateDrawObject::DrawTerrain(std::vector<Terrain> terrainBlocks) {

    //iterate through every terrain block
    for (std::vector<Terrain>::iterator it = terrainBlocks.begin(); it != terrainBlocks.end(); ++it) {
        switch((*it).getTerrainType()){
            case CORNER_TOP_LEFT:
                cornerTopLeftTerrainSprite.setPosition((*it).getX1(),(*it).getY1());
                window.draw(cornerTopLeftTerrainSprite);
                break;
            case CORNER_TOP_RIGHT:
                cornerTopRightTerrainSprite.setPosition((*it).getX1(),(*it).getY1());
                window.draw(cornerTopRightTerrainSprite);
                break;
            case CORNER_BOTTOM_LEFT:
                cornerBottomLeftTerrainSprite.setPosition((*it).getX1(),(*it).getY1());
                window.draw(cornerBottomLeftTerrainSprite);
                break;
            case CORNER_BOTTOM_RIGHT:
                cornerBottomRightTerrainSprite.setPosition((*it).getX1(),(*it).getY1());
                window.draw(cornerBottomRightTerrainSprite);
                break;
            case VERTICAL:
                verticalTerrainSprite.setPosition((*it).getX1(),(*it).getY1());
                window.draw(verticalTerrainSprite);
                break;
            case HORIZONTAL:
                horizontalTerrainSprite.setPosition((*it).getX1(),(*it).getY1());
                window.draw(horizontalTerrainSprite);
                break;
            case BUILDABLE:
                buildableTerrainSprite.setPosition((*it).getX1(),(*it).getY1());
                window.draw(buildableTerrainSprite);
                break;
            default:
                undefinedTerrainSprite.setPosition((*it).getX1(),(*it).getY1());
                window.draw(undefinedTerrainSprite);
                break;
        }
    }
}
