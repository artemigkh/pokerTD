//
// Created by Artem on 10/7/2017.
//

#ifndef POKERTD_UNIT_H
#define POKERTD_UNIT_H

#include<string>

class Unit {
public:
    Unit(const std::string &name, const std::string &description, int currHP, int size, int speed, float currPosX,
         float currPosY, int orientation, int spriteSheetID, int spriteSheetOffsetX, int spriteSheetOffsetY);

    void Update();

    const std::string &getName() const;
    const std::string &getDescription() const;
    int getCurrHP() const;
    int getOrientation() const;
    int getFramePos() const;
    int getSpriteSheetID() const;
    int getSpriteSheetOffsetX() const;
    int getSpriteSheetOffsetY() const;
    float getCurrPosX() const;
    float getCurrPosY() const;

private:
    std::string name;
    std::string description;

    int currHP;
    int size;
public:
    int getSize() const;

private:
    int speed;
    float currPosX;
    float currPosY;

    int orientation;
    int framePosCounter;
    int framePos;
    float tickMoveSpeed;

    int spriteSheetID;
    int spriteSheetOffsetX;
    int spriteSheetOffsetY;
};


#endif //POKERTD_UNIT_H
