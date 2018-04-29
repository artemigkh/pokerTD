//
// Created by Artem on 10/6/2017.
//

#ifndef POKERTD_SPRITEDRAWOBJECT_H
#define POKERTD_SPRITEDRAWOBJECT_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

class SpriteDrawObject {
public:
    SpriteDrawObject(sf::RenderWindow &window, std::string fileName);

    //orientation: 0: down, 1: left, 2: right, 3: up
    void Draw(float windowPosX, float windowPosY, int windowSizeWidth, int windowSizeHeight, int groupOffsetX,
              int groupOffsetY, int frame, int orientation, float healthPercent);
private:
    void DrawHealthBar(float windowPosX, float windowPosY, int windowSizeWidth, int windowSizeHeight, float healthPercent);

    int getXofSpriteSheet(int groupOffsetX, int frame);
    int getYofSpriteSheet(int groupOffsetY, int orientation);

    sf::RenderWindow& window;
    sf::Texture spriteSheet;
};


#endif //POKERTD_SPRITEDRAWOBJECT_H
