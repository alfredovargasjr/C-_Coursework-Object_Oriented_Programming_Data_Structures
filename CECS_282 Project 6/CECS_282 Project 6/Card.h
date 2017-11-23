#pragma once
#ifndef Card_h
#define Card_h
using namespace std;
#include <string>
class Card {
public:
	enum Face { Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
	enum Suit { Clubs, Diamonds, Hearts, Spades };
private:
	Face face;
	Suit suit;
public:
	//enum of face
	string faceArray[13] = { "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace" };
	//enum of suit
	string suitArray[4] = { "Clubs", "Diamonds", "Hearts", "Spade" };
	//default
	Card();
	//pass in int, turn to enum
	Card(int, int);
	//get face of card
	int getFace();
	//get suit of card
	int getSuit();
	string toString();
};

#endif // !CARD_H

