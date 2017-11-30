//
// Created by Artem on 11/29/2017.
//

#include <algorithm>
#include <iostream>
#include "../../include/Deck.h"

Deck::Deck() {
    ResetDeck();
    ShuffleDeck();
}

void Deck::ResetDeck() {
    for(int suit = HEART; suit <= DIAMOND; suit++){
        for(int value = ACE; value <= KING; value++){
            cards.push_back(Card(static_cast<Suit>(suit), static_cast<CardValue>(value)));
        }
    }
}

void Deck::ShuffleDeck() {
    std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::PopTopCard() {
    Card toReturn = cards.back();
    cards.pop_back();
    return toReturn;
}

void Deck::PrintDeck() {
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
