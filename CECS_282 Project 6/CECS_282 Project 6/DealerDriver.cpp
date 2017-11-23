/*
	Alfredo Vargas
	CECS 282
	Project 6: Cards and dealer
	Susan*/

using namespace std;
#include "Card.h"
#include "Hand.h"
#include "DeckOfCards.h"
#include <stdio.h>
#include <iostream>
#include <string>

void display(DeckOfCards d) {
	for (int i = 0; i < 52; i++) {
		if (i != 0 && i % 4 == 0)
			cout << endl;
		printf("%-18s", d.deck[i].toString().c_str());
	}
}

void menu() {
	bool flag;
	int choice;
	DeckOfCards dk = DeckOfCards();
	dk.shuffle();
	Hand h;
	do {
		flag = false;
		cout << "\nMenu: \n[1]Get Hand \n[2]Shuffle \n[0]Exit";
		cin >> choice;
		switch (choice) {
		case 1:
			dk.shuffle();
			h = Hand(dk);
			h.display();
			h.checkHand();
			break;
		case 2:
			dk.shuffle();
			break;
		case 0:
			flag = true;
			break;
		default:
			cout << "\nInvalid Entry. Re-enter.";
			break;		
		}
		cin.clear();
		cin.ignore();
	} while (!flag);
}

int main() {
	DeckOfCards d = DeckOfCards();
	cout << "Deck: \n";
	display(d);
	cout << endl << endl;
	cout << "Shuffled Deck: \n";
	d.shuffle();
	display(d);
	cout << endl << endl;
	cout << "Cards Dealed: \n";
	int i = 0;
	while (d.moreCards()) {
		if (i != 0 && i % 4 == 0)
			cout << endl;
		printf("%-18s", d.dealCard().toString().c_str());
		i++;
	}
	d.resetCardCount();
	cout << endl << endl;
	menu();
	cout << "\nProgram Exit.";
	system("pause");
}