//
// Created by Artem on 9/30/2017.
//
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    // create the window
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window", sf::Style::Default, settings);

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        sf::CircleShape shape(50);
        shape.setFillColor(sf::Color(150, 50, 250));

        // set a 10-pixel wide orange outline
        shape.setOutlineThickness(10);
        shape.setOutlineColor(sf::Color(250, 150, 100));

        shape.setPosition(150,150);

        window.draw(shape);

        // end the current frame
        window.display();
    }

    return 0;
}