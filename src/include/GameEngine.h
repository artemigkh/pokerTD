//
// Created by Artem on 10/2/2017.
//

#ifndef POKERTD_GAMEENGINE_H
#define POKERTD_GAMEENGINE_H

#include<vector>

class GameStateInterface;

class GameEngine {
public:
    void Init();
    void Cleanup();

    void changeState(GameStateInterface *state);
    void PushState(GameStateInterface *state);
    void PopState();

    void HandleEvents();
    void Update();
    void Draw();

    bool Running();
    void Quit();

private:
    std::vector<GameStateInterface*> states;
    bool running;
};


#endif //POKERTD_GAMEENGINE_H
