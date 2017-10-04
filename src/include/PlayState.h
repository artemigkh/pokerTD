//
// Created by Artem on 10/3/2017.
//

#ifndef POKERTD_PLAYSTATE_H
#define POKERTD_PLAYSTATE_H

#include "GameStateInterface.h"

class PlayState : public GameStateInterface{
public:
    PlayState(sf::RenderWindow &window);

    static PlayState *getInstance();

    void Init() override;

    void Pause() override;

    void Resume() override;

    void Update(GameEngine *game) override;

    void Draw(GameEngine *game) override;

    void Cleanup() override;

private:
    static PlayState* PlayStateInstance;
    sf::RenderWindow& window;
    int x;
    int y;
};


#endif //POKERTD_PLAYSTATE_H
