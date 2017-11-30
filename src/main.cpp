//
// Created by Artem on 9/30/2017.
//
#include <iostream>

#include "include/GameEngine.h"
#include "include/Deck.h"

using namespace std;

int main()
{
//    GameEngine game;
//    game.Run();

    Deck d1;
    d1.PrintDeck();

    std::cout<<"--------------------------" << std::endl;

    Deck d2;
    d2.PrintDeck();

    return 0;
}