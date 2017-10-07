//
// Created by Artem on 10/6/2017.
//
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>

#include "../../include/SpriteDrawObject.h"
#include "GraphicsConstants.h"
#include "../../include/GameConstants.h"


SpriteDrawObject::SpriteDrawObject(sf::RenderWindow &window, std::string fileName) : window(window) {
    if (!spriteSheet.loadFromFile(std::string("res/img/units/") + fileName)) {
        std::cerr << "Could not load file " << fileName;
        spriteSheet.create(gac::SQUARE_WIDTH_UNSIGNED, gac::SQUARE_HEIGHT_UNSIGNED);
    }
}

void
SpriteDrawObject::Draw(int windowPosX, int windowPosY, int windowSizeWidth, int windowSizeHeight, int groupOffsetX,
                       int groupOffsetY, int orientation, int frame) {
    sf::Sprite drawingSprite;
    drawingSprite.setTexture(spriteSheet);
    drawingSprite.setTextureRect(sf::IntRect(getXofSpriteSheet(groupOffsetX, frame),
                                             getYofSpriteSheet(groupOffsetY, orientation),
                                             grc::SPRITE_WIDTH, grc::SPRITE_HEIGHT));
    drawingSprite.setPosition(windowPosX, windowPosY);
    //TODO: set scaling factor by using width and height
    window.draw(drawingSprite);
}

int SpriteDrawObject::getXofSpriteSheet(int groupOffsetX, int frame) {
    return groupOffsetX * grc::SPRITE_SHEET_GROUP_WIDTH +
           frame * grc::SPRITE_WIDTH;
}

int SpriteDrawObject::getYofSpriteSheet(int groupOffsetY, int orientation) {
    return groupOffsetY * grc::SPRITE_SHEET_GROUP_HEIGHT +
           orientation * grc::SPRITE_HEIGHT;
}
