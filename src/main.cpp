//
// Created by Artem on 9/30/2017.
//
#include <iostream>

#include "include/GameEngine.h"
#include "include/Deck.h"
#include "include/HandsEnum.h"
#include "include/PokerHand.h"

using namespace std;

void printHand(std::vector<Card> cards){
    for(std::vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
        Suit currSuit = (*it).getSuit();
        switch(currSuit){
            case HEART:
                std::cout << "Heart ";
                break;
            case SPADE:
                std::cout << "Spade ";
                break;
            case CLUB:
                std::cout << "Club ";
                break;
            case DIAMOND:
                std::cout << "Diamond ";
                break;
            default:
                std::cout << "UNDEFINED ";
                break;
        }

        CardValue currValue = (*it).getCardValue();
        switch(currValue){
            case ACE:
                std::cout << "Ace" << std::endl;
                break;
            case TWO:
                std::cout << "2" << std::endl;
                break;
            case THREE:
                std::cout << "3" << std::endl;
                break;
            case FOUR:
                std::cout << "4" << std::endl;
                break;
            case FIVE:
                std::cout << "5" << std::endl;
                break;
            case SIX:
                std::cout << "6" << std::endl;
                break;
            case SEVEN:
                std::cout << "7" << std::endl;
                break;
            case EIGHT:
                std::cout << "8" << std::endl;
                break;
            case NINE:
                std::cout << "9" << std::endl;
                break;
            case TEN:
                std::cout << "10" << std::endl;
                break;
            case JACK:
                std::cout << "Jack" << std::endl;
                break;
            case QUEEN:
                std::cout << "Queen" << std::endl;
                break;
            case KING:
                std::cout << "King" << std::endl;
                break;
            default:
                std::cout << "UNDEFINED" << std::endl;
                break;
        }
    }
}

int main()
{
    GameEngine game;
    game.Run();
}