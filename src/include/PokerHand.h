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
    PokerHand(const std::vector<Card> &cards);
    Hand getHand();
//    CardValue getHighCard();

private:
    std::vector<Card> cards;

private:
//    CardValue highCard;
    Hand hand;

    int NumCards[15];
    int NumSameValues[5];
    int Suits[4];
    CardValue smallestValue;

    void ComputeHand();
    void PreSort();

    bool isRoyalFlush();
    bool isStraightFlush();
    bool isFourOfAKind();
    bool isFullHouse();
    bool isFlush();
    bool isStraight();
    bool isThreeOfAKind();
    bool isTwoPair();
    bool isPair();
};


#endif //POKERTD_HAND_H
