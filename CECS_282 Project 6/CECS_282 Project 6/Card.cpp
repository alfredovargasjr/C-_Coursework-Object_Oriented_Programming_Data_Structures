
using namespace std;
#include <string>
#include <iostream>
#include "Card.h"

	//default
	Card::Card() {
		face = Two;
		suit = Clubs;
	}
	//pass in int, turn to enum
	Card::Card(int f, int s) {
		face = Face(f);
		suit = Suit(s);
	}
	//get face of card
	int Card::getFace() {
		return Face(face);
	}
	//get suit of card
	int Card::getSuit() {
		return Suit(suit);
	}
	string Card::toString() {
		return faceArray[Face(face)] + " of " + suitArray[Suit(suit)];
	}
