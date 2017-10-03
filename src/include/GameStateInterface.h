//
// Created by Artem on 10/2/2017.
//

#ifndef POKERTD_GAMESTATEINTERFACE_H
#define POKERTD_GAMESTATEINTERFACE_H

class GameStateInterface;

class GameStateInterface {
public:
    virtual void Init() = 0;
    virtual void Cleanup() = 0;

    virtual void Pause() = 0;
    virtual void Resume() = 0;

};


#endif //POKERTD_GAMESTATEINTERFACE_H
