//
// Created by Artem on 11/29/2017.
//

#include "../../include/Card.h"

Card::Card(Suit suit, CardValue cardValue) : suit(suit), cardValue(cardValue) {}

Suit Card::getSuit() const {
    return suit;
}

CardValue Card::getCardValue() const {
    return cardValue;
}

Card::Card(const Card &card) {
    suit = card.getSuit();
    cardValue = card.getCardValue();
}
