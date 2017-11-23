#pragma once
#ifndef Hand_h
#define Hand_h
using namespace std;
#include "Card.h"
#include "DeckOfCards.h"
class Hand {
private:
	Card hand[5];

public:
	//default
	Hand();
	//pass deck of cards
	Hand(DeckOfCards de);
	//return true if has pair
	bool hasPair();
	//return true of has two pairs
	bool hasTwoPairs();
	//return true if has three of a kind
	bool hasThreeKind();
	//return true if has four of a kind
	bool hasFourKind();
	//return true if has a flush
	bool hasFlush();
	bool hasStraight();
	void checkHand();
	void display();
};
#endif // !Hand_h

