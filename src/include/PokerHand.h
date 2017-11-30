//
// Created by Artem on 11/29/2017.
//

#ifndef POKERTD_HAND_H
#define POKERTD_HAND_H

#include <vector>
#include "Card.h"
#include "HandsEnum.h"

class PokerHand {
public:
    PokerHand(Card &c1, Card &c2, Card &c3, Card &c4, Card &c5);
    Hand getHand();
    CardValue getHighCard();

private:
    std::vector<Card> cards;
    CardValue highCard;
    Hand hand;

    void SetHighCard();
    void ComputeHand();
};


#endif //POKERTD_HAND_H
