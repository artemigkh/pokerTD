//
// Created by Artem on 11/29/2017.
//

#ifndef POKERTD_DECK_H
#define POKERTD_DECK_H

#include <vector>
#include "Card.h"
#include "../Poker/Cards/CardValuesEnum.h"

class Deck {
public:
    Deck();
    void RestoreDeck();
    void ResetDeck();
    void ShuffleDeck();
    Card PopTopCard();
    void PrintDeck();

private:
    std::vector<Card> cards;
    std::vector<Card> cardsBackup;
};


#endif //POKERTD_DECK_H
