//
// Created by Artem on 11/29/2017.
//

#include "../../include/PokerHand.h"

CardValue max(CardValue c1, CardValue c2){
    if(c1 > c2){
        return c1;
    } else {
        return c2;
    }
}


PokerHand::PokerHand(const std::vector<Card> &cards) : cards(cards) {
    for(int i = 0; i < 15; i++){
        NumCards[i] = 0;
    }

    for(int i = 0; i < 4; i++){
        Suits[i] = 0;
    }

    for(int i = 0; i < 5; i++){
        NumSameValues[i] = 0;
    }

    PreSort();
    ComputeHand();
}

PokerHand::PokerHand(Card &c1, Card &c2, Card &c3, Card &c4, Card &c5) {
    cards.push_back(c1);
    cards.push_back(c2);
    cards.push_back(c3);
    cards.push_back(c4);
    cards.push_back(c5);

    for(int i = 0; i < 15; i++){
        NumCards[i] = 0;
    }

    for(int i = 0; i < 4; i++){
        Suits[i] = 0;
    }

    for(int i = 0; i < 5; i++){
        NumSameValues[i] = 0;
    }

    PreSort();
    ComputeHand();
}

Hand PokerHand::getHand() {
    return hand;
}

//CardValue PokerHand::getHighCard() {
//    return highCard;
//}

void PokerHand::ComputeHand() {
    if(isRoyalFlush()){
        hand = ROYAL_FLUSH;
    } else if(isStraightFlush()){
        hand = STRAIGHT_FLUSH;
    } else if(isFourOfAKind()){
        hand = FOUR_OF_A_KIND;
    } else if(isFullHouse()){
        hand = FULL_HOUSE;
    } else if(isFlush()){
        hand = FLUSH;
    } else if(isStraight()){
        hand = STRAIGHT;
    } else if(isThreeOfAKind()){
        hand = THREE_OF_A_KIND;
    } else if(isTwoPair()){
        hand = TWO_PAIR;
    } else if(isPair()){
        hand = PAIR;
    } else {
        hand = HIGH_CARD;
    }
}

void PokerHand::PreSort() {
    smallestValue = ACE;
    for(std::vector<Card>::iterator it = cards.begin(); it != cards.end(); ++it) {
        CardValue value = (*it).getCardValue();
        NumCards[value]++;
        Suits[(*it).getSuit()]++;
        if(value < smallestValue){
            smallestValue = value;
        }
        if(value == ACE){
            NumCards[LOW_ACE]++;
        }
    }
    for(int i = TWO; i < 15; i++){
        NumSameValues[NumCards[i]]++;
    }
}

bool PokerHand::isFlush() {
    return Suits[HEART] == 5 || Suits[SPADE] == 5 ||
           Suits[CLUB] == 5 || Suits[DIAMOND] == 5;
}

bool PokerHand::isStraight() {
    if(smallestValue >= JACK){
        return false;
    }
    else {
        return NumCards[smallestValue + 1] == 1 && NumCards[smallestValue + 2] == 1 &&
               NumCards[smallestValue + 3] == 1 && NumCards[smallestValue + 4] == 1;
    }
}

bool PokerHand::isStraightFlush() {
    return isStraight() && isFlush();
}

bool PokerHand::isRoyalFlush() {
    return isStraightFlush() && smallestValue == TEN;
}

bool PokerHand::isFourOfAKind() {
    return NumSameValues[4] == 1;
}

bool PokerHand::isThreeOfAKind() {
    return NumSameValues[3] == 1;
}

bool PokerHand::isTwoPair() {
    return NumSameValues[2] == 2;
}

bool PokerHand::isPair() {
    return NumSameValues[2] == 1;
}

bool PokerHand::isFullHouse() {
    return NumSameValues[3] == 1 && NumSameValues[2] == 1;
}










