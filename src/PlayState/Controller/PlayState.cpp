//
// Created by Artem on 10/3/2017.
//
#include "../../include/PlayState.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

PlayState *PlayState::PlayStateInstance = 0;

void PlayState::Init() {
    x = 0;
    y = 0;
}

void PlayState::Pause() {

}

void PlayState::Resume() {

}

void PlayState::HandleUserInput(GameEngine *game) {
    // clear the window with black color


    //check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {
        // "close requested" event: we close the window
        if (event.type == sf::Event::Closed) {
            window.close();
            game->Stop();
        }
        else if(event.type == sf::Event::MouseMoved){
            x = event.mouseMove.x;
            y = event.mouseMove.y;
        }

    }
//
//    sf::CircleShape shape(50);
//    shape.setFillColor(sf::Color(150, 50, 250));
//
//    // set a 10-pixel wide orange outline
//    shape.setOutlineThickness(10);
//    shape.setOutlineColor(sf::Color(250, 150, 100));
//
//    shape.setPosition(x-50, y-50);
//
//    window.draw(shape);
//
//    // end the current frame
//
}

void PlayState::Update(GameEngine *game) {

}

void PlayState::Draw(GameEngine *game) {
    window.clear(sf::Color::Black);
    model->Draw(drawObject);
    window.display();
}

void PlayState::Cleanup() {

}

PlayState::PlayState(sf::RenderWindow &window) : window(window) {
    PlayStateInstance = this;
    model = new PlayStateModel();
    drawObject = new PlayStateDrawObject(window);
}

PlayState *PlayState::getInstance() {
    return PlayStateInstance;
}

