//
// Created by Artem on 10/2/2017.
//

#ifndef POKERTD_GAMEENGINE_H
#define POKERTD_GAMEENGINE_H

#include<vector>

#include <SFML/Window.hpp>

class GameStateInterface;

class GameEngine {
public:
    void Run();
    void Cleanup();

    void changeState(GameStateInterface *state);
    void PushState(GameStateInterface *state);
    void PopState();

    void Stop();

private:
    void Update();
    void Draw();

    std::vector<GameStateInterface*> states;
    bool running;
};


#endif //POKERTD_GAMEENGINE_H
