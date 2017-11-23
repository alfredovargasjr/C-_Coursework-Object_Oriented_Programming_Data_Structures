#include <iostream>
using namespace std;
#include "Hand.h"

	//default
	Hand::Hand() {
		hand[0] = Card();
	}
	//pass deck of cards
	Hand::Hand(DeckOfCards de) {
		for (int i = 0; i < 5; i++) {
			hand[i] = de.dealCard();
		}
	}
	//return true if has pair
	bool Hand::hasPair() {
		int i = 0, j = 4;
		while (i < 4) {
			if (hand[i].getFace() == hand[j].getFace()) {
				return true;
			}
			if (j - 1 == i) {
				i++;
				j = 5;
			}
			j--;
		}
		return false;
	}
	//return true of has two pairs
	bool Hand::hasTwoPairs() {
		int i = 0, j = 4;
		int numPairs = 0;
		while (i < 4) {
			if ((hand[i].getFace() == hand[j].getFace()) && i != j) {
				numPairs++;
				cout << hand[i].getFace() << hand[j].getFace();
				i++;
				j = 5;
			}
			if (j - 1 == i) {
				i++;
				j = 5;
			}
			j--;
		}
		if (numPairs == 2)
			return true;
		return false;

	}
	//return true if has three of a kind
	bool Hand::hasThreeKind() {
		int i = 0, j = 4;
		int temp, prev;
		int match = 0;
		while (i < 4) {
			if (hand[i].getFace() == hand[j].getFace()) {
				match++;
			}
			if (j - 1 == i) {
				i++;
				j = 5;
				match = 0;
			}
			j--;
		}
		if (match == 3)
			return true;
		return false;
	}
		//return true if has four of a kind
		bool Hand::hasFourKind() {
			int i = 0, j = 4;
			int temp, prev;
			int match = 0;
			while (i < 4) {
				if (hand[i].getFace() == hand[j].getFace()) {
					match++;
				}
				if (j - 1 == i) {
					i++;
					j = 5;
					match = 0;
				}
				j--;
			}
			if (match == 4)
				return true;
			return false;
		}
		//return true if has a flush
		bool Hand::hasFlush() {
			int i = 0, j = 4;
			int match = 0;
			while (i < 1) {
				if (hand[i].getSuit() == hand[j].getSuit()) {
					match++;
				}
				if (j - 1 == i) {
					i++;
					j = 5;
					match = 0;
				}
				j--;
			}
			if (match == 5)
				return true;
			return false;
	}
		bool Hand::hasStraight() {
			int i = 0, j = 1;
			int temp, prev;
			int match = 0;
			while (i < 1) {
				if (hand[i].getFace() - hand[j].getFace() == -j) {
					match++;
				}
				if (j == 4) {
					i++;
				}
				j++;
			}
			if (match == 4)
				return true;
			return false;
		}
		void Hand::checkHand() {
			if (hasStraight())
				cout << "\nHas Straight!";
			else if (hasFlush())
				cout << "\nHas Flush!";
			else if (hasFourKind())
				cout << "\nHas Four of a kind!";
			else if (hasStraight())
				cout << "\nHas Straight!";
			else if (hasPair())
				cout << "\nHas Pair!";
			else if (hasThreeKind())
				cout << "\nHas three of a kind!";
			else if (hasTwoPairs())
				cout << "\nHas Two pairs!";
			else
				cout << "\nNothing!";
		}
	void Hand::display() {
		for (int i = 0; i < 5; i++) {
			cout << hand[i].toString() << endl;
		}
	}