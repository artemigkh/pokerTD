//
// Created by Artem on 11/29/2017.
//

#ifndef POKERTD_CARD_H
#define POKERTD_CARD_H


#include "../Poker/Cards/SuitsEnum.h"
#include "../Poker/Cards/CardValuesEnum.h"

class Card {
public:
    Card(Suit suit, CardValue value);
    Suit getSuit() const;
    CardValue getCardValue() const;

private:
    Suit suit;
    CardValue cardValue;
};


#endif //POKERTD_CARD_H
