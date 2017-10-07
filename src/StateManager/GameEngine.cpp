//
// Created by Artem on 10/2/2017.
//

#include <iostream>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../include/GameEngine.h"
#include "../include/GameStateInterface.h"
#include "../include/PlayState.h"

#include "../include/GameConstants.h"

void GameEngine::Run() {
    std::cout << "Game Engine Initialized" << std::endl;
    //create the window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(gac::WINDOW_WIDTH, gac::WINDOW_HEIGHT),
                            "Poker Tower Defense", sf::Style::Titlebar | sf::Style::Close, settings);
    //window.setMouseCursorVisible(false);

    //create clock
    sf::Clock clock;

    //create the states
    PlayState playState(window);

    //push on first state
    PushState(PlayState::getInstance());

    // run the program as long as the window is open
    while (window.isOpen()) {
        //start game loop
        while (running) {
            clock.restart();

            HandleUserInput();
            Update();
            Draw();

            //limit fps
            //TODO: Use an actual timer here instead of spinning
            while (clock.getElapsedTime().asMilliseconds() < 1000 / gac::FRAMES_PER_SECOND) {}
        }
    }
}

void GameEngine::Cleanup() {
    std::cout << "Game Engine Cleanup Started" << std::endl;
    while (!states.empty()) {
        states.back()->Cleanup();
        states.pop_back();
    }
}

void GameEngine::changeState(GameStateInterface *state) {
    if (!states.empty()) {
        states.back()->Cleanup();
        states.pop_back();
    }

    states.push_back(state);
    states.back()->Init();
}

void GameEngine::PushState(GameStateInterface *state) {
    // pause current state
    if (!states.empty()) {
        states.back()->Pause();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init();
}

void GameEngine::PopState() {
    // cleanup the current state
    if (!states.empty()) {
        states.back()->Cleanup();
        states.pop_back();
    }

    // resume previous state
    if (!states.empty()) {
        states.back()->Resume();
    }
}

void GameEngine::Update() {
    // let the state update the game
    states.back()->Update(this);
}

void GameEngine::Draw() {
    // let the state draw the screen
    states.back()->Draw(this);
}

void GameEngine::Stop() {
    running = false;
}

void GameEngine::HandleUserInput() {
    states.back()->HandleUserInput(this);
}

