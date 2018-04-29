//
// Created by Artem on 10/6/2017.
//
#include <iostream>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

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
SpriteDrawObject::Draw(float windowPosX, float windowPosY, int windowSizeWidth, int windowSizeHeight, int groupOffsetX,
                       int groupOffsetY, int frame, int orientation, float healthPercent) {
    sf::Sprite drawingSprite;
    drawingSprite.setTexture(spriteSheet);
    drawingSprite.setTextureRect(sf::IntRect(getXofSpriteSheet(groupOffsetX, frame),
                                             getYofSpriteSheet(groupOffsetY, orientation),
                                             grc::SPRITE_WIDTH, grc::SPRITE_HEIGHT));
    drawingSprite.setPosition(windowPosX - (float)windowSizeWidth / 2, windowPosY - (float)windowSizeHeight / 2);
    //TODO: set scaling factor by using width and height
    window.draw(drawingSprite);
    DrawHealthBar(windowPosX, windowPosY, windowSizeWidth, windowSizeHeight, healthPercent);
}

int SpriteDrawObject::getXofSpriteSheet(int groupOffsetX, int frame) {
    return groupOffsetX * grc::SPRITE_SHEET_GROUP_WIDTH +
           frame * grc::SPRITE_WIDTH;
}

int SpriteDrawObject::getYofSpriteSheet(int groupOffsetY, int orientation) {
    return groupOffsetY * grc::SPRITE_SHEET_GROUP_HEIGHT +
           orientation * grc::SPRITE_HEIGHT;
}

void SpriteDrawObject::DrawHealthBar(float windowPosX, float windowPosY, int windowSizeWidth, int windowSizeHeight, float healthPercent) {
    int greenWidth = grc::HP_BAR_WIDTH * healthPercent;
    int redWidth = grc::HP_BAR_WIDTH - greenWidth;

    sf::RectangleShape healthBarGreen;
    healthBarGreen.setSize(sf::Vector2f(greenWidth, grc::HP_BAR_HEIGHT));
    healthBarGreen.setPosition(windowPosX - (float)windowSizeWidth / 2,
                          windowPosY - (float)windowSizeHeight / 2 + grc::SPRITE_WIDTH - grc::HP_BAR_OFFSET);
    healthBarGreen.setFillColor(sf::Color::Green);
    window.draw(healthBarGreen);

    sf::RectangleShape healthBarRed;
    healthBarRed.setSize(sf::Vector2f(redWidth, grc::HP_BAR_HEIGHT));
    healthBarRed.setPosition(windowPosX - (float)windowSizeWidth / 2 + greenWidth,
                               windowPosY - (float)windowSizeHeight / 2 + grc::SPRITE_WIDTH - grc::HP_BAR_OFFSET);
    healthBarRed.setFillColor(sf::Color::Red);
    window.draw(healthBarRed);
}
