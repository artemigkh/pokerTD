//
// Created by Artem on 11/29/2017.
//

#include "../../include/PokerHand.h"

PokerHand::PokerHand(Card &c1, Card &c2, Card &c3, Card &c4, Card &c5) {
    cards.push_back(c1);
    cards.push_back(c2);
    cards.push_back(c3);
    cards.push_back(c4);
    cards.push_back(c5);

    SetHighCard();

    ComputeHand();
}

Hand PokerHand::getHand() {
    return hand;
}

CardValue PokerHand::getHighCard() {
    return highCard;
}

//TODO: set to high card of card thats part of highest hand
void PokerHand::SetHighCard() {
    highCard = TWO;
    for(std::vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
        if((*it).getCardValue() > highCard){
            highCard = (*it).getCardValue();
        }
    }
}

void PokerHand::ComputeHand() {

}
