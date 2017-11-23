
#include <iostream>
#include <ctime>
#include "DeckOfCards.h"
using namespace std;
	//default constructor
	DeckOfCards::DeckOfCards() {
		int f = 0, s = 0;
		for (int i = 0; i < 52; i++) {
			deck[i] = Card(f%13, s%4);
			f++;
			if (f % 13 == 0) {
				s++;
			}
		}
	}
	//shuffle method, replace card positions
	void DeckOfCards::shuffle() {
		Card temp;
		int r;
		for (int i = 0; i < 52; i++) {
			r = (rand() % 52);
			while (i == r) {
				r = abs((rand() % 52));
			}
			temp = deck[i];
			deck[i] = deck[r];
			deck[r] = temp;
		}	
	}
	//deal a card, current card will be returned
	Card DeckOfCards::dealCard() {
		Card t = deck[currentCard];
		currentCard++;
		return t;
	}
	//if there is no next card, return false
	bool DeckOfCards::moreCards() {
		if (currentCard > 51)
			return false;
		return true;
	}
	int DeckOfCards::getCurrent() {
		return currentCard;
	}
	void DeckOfCards::resetCardCount() {
		currentCard = 0;
	}