//
// Created by Artem on 10/2/2017.
//

#include "../include/GameEngine.h"
#include "../include/GameStateInterface.h"

#include <iostream>

void GameEngine::Init() {
    std::cout << "Game Engine Initialized" << std::endl;
}

void GameEngine::Cleanup() {
    std::cout << "Game Engine Cleanup Started" << std::endl;
    while ( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }
}

void GameEngine::changeState(GameStateInterface *state) {
    if ( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }

    states.push_back(state);
    states.back()->Init();
}

void GameEngine::PushState(GameStateInterface *state) {
    // pause current state
    if ( !states.empty() ) {
        states.back()->Pause();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init();
}
void GameEngine::PopState()
{
    // cleanup the current state
    if ( !states.empty() ) {
        states.back()->Cleanup();
        states.pop_back();
    }

    // resume previous state
    if ( !states.empty() ) {
        states.back()->Resume();
    }
}

void GameEngine::HandleEvents()
{
    // let the state handle events
//    states.back()->HandleEvents(this);
}

void GameEngine::Update()
{
    // let the state update the game
//    states.back()->Update(this);
}

void GameEngine::Draw()
{
    // let the state draw the screen
//    states.back()->Draw(this);
}

bool GameEngine::Running() {
    return this->running;
}

void GameEngine::Quit() {
    this->running = false;
}

