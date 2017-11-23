#pragma once
#ifndef DeckOfCards_h
#define DeckOfCards_h
using namespace std;
#include "Card.h"
class DeckOfCards {
public:
	Card deck[52];
private:
	int currentCard = 0;
public:
	//default constructor
	DeckOfCards();
	//shuffle method, replace card positions
	void shuffle();
	//deal a card, current card will be returned
	Card dealCard();
	//if there is no next card, return false
	bool moreCards();
	int getCurrent();
	void resetCardCount();

};
#endif // !DeackOfCards_h

