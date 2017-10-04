//
// Created by Artem on 10/2/2017.
//

#ifndef POKERTD_GAMESTATEINTERFACE_H
#define POKERTD_GAMESTATEINTERFACE_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "../include/GameEngine.h"

class GameStateInterface {
public:
    virtual void Init() = 0;
    virtual void Cleanup() = 0;

    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void Update(GameEngine* game) = 0;
    virtual void Draw(GameEngine* game) = 0;

    ~GameStateInterface();

};
#endif //POKERTD_GAMESTATEINTERFACE_H
