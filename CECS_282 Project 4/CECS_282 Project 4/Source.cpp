/*
	Alfredo Vargas
	CECS 282
	Project 4: Calculator

	*/

using namespace std;
#include <iostream>;
#include <ctype.h>;
#include <string>;
#include "Operations.h";
#include "Ins.h";
#include <stdlib.h>;

/*
	takes in the reference of value a and b
	*/
void learnMode(double *a, double *b) {
	char choice;
	bool flag;
	do {
		flag = false;
		cout << "\nLearning Mode:\n[A] Enter Manually\n[B] Get Random\n[0] Exit\n";
		cout << "Choice: ";
		cin >> choice;
		choice = toupper(choice);
		switch (choice) {
		case 'A':
			getVal(a);
			getVal(b);
			break;
		case 'B':
			*a = (rand() % 10 + 1) * 1.0;
			for (int i = 0; i < 100; i++);
			*b = (rand() % 10 + 1) * 1.0;
			break;
		case '0':
			flag = false;
			break;
		default:
			cout << "\nInvalid Entry. Re-enter.";
			system("pause");
			flag = true;
			break;
		}
	} while (flag);
	
	
}

/*
	menu for the operation
	use the header file for the operation methods
	*/

void learnModeOperations() {
	char choice;
	bool flag;
	double a = 0;
	double b = 0;
	do {
		flag = true;
		cout << "\nOperations:\n[A] Addition\n[B] Subtraction\n[C] Multiplication\n[D] Division\n[E] Remainder\n[F] Power \n[G] Sine\n[H] Cosine\n[0] Exit";
		cout << "\nChoice: ";
		cin >> choice;
		choice = char(toupper(choice));
		learnMode(&a, &b);
		switch (choice) {
		case 'A':
			outs("+", a, b);
			cout << addition(a, b);;
			break;
		case 'B':
			outs("-", a, b);
			cout << subtraction(a, b);
			break;
		case 'C':
			outs("*", a, b);
			cout << multiplication(a, b);
			break;
		case 'D':
			outs("\\", a, b);
			cout << dDivision(a, b);
			break;
		case 'E':
			outs("%", a, b);
			cout << modul(a, b);
			break;
		case 'F':
			outs("^", a, b);
			cout << pow(a, b);
			break;
		case 'G':
			cout << "sin(" << a << ") = " << sine(a);
			cout << "\nsin(" << b << ") = " << sine(b);
			break;
		case 'H':
			cout << "cos(" << a << ") = " << cosine(a);
			cout << "\ncos(" << b << ") = " << cosine(b);
			break;
		case '0':
			flag = false;
			break;
		default:
			cout << "\nInvalid Entry. Re-enter\n";
			system("pause");
			flag = true;
			break;
		}
		cout << endl; 
		system("pause");
	} while (flag);
}

void GameOperations(int lv) {	//lv = level
	bool flag;
	double a = 0, b = 0, answer;
	int round = 1, score = 0, level = lv, questionNum = 1, question = 1;
	double userAnswer;
	int operation;
	int t;	//determine the number of digits
	//get one digit numbers
	if (level == 1) {
		t = 10;
		cout << "\nOperations:\n[1] Addition\n[2] Subtraction\n[3] Multiplication\n[4] Division\n" << "Choice: ";
		cin >> operation;
	}
	do {	//run 3 rounds
		cout << "\nLEVEL " << level << ": ";
		cout << "\nRound " << round << ": ";
		do {	//ask 5 questions = 1 round
			
			//get two digit number
			if (level == 2) {
				t = 100;
				operation = (rand() % 8) + 1;	//use rand to get random operation 1 - 8
			}
			//get three digit number
			if (level >= 3) {
				t = 1000;
				operation = (rand() % 8) + 1;
			}
			cout << "\nQuestion " << questionNum << ": \n";
			//get a and b as rand numbers using t as number of digits
			a = (rand() % t + 1) * 1.0;
			for (int i = 0; i < 100; i++);
			b = (rand() % t + 1) * 1.0;
			flag = true;
			switch (operation) {
			case 1:
				outs("+", a, b);
				answer = addition(a, b);;
				break;
			case 2:
				outs("-", a, b);
				answer = subtraction(a, b);
				break;
			case 3:
				outs("*", a, b);
				answer = multiplication(a, b);
				break;
			case 4:
				outs("\\", a, b);
				answer = dDivision(a, b);
				break;
			case 5:
				outs("%", a, b);
				answer = modul(a, b);
				break;
			case 6:
				outs("^", a, b);
				answer = pow(a, b);
				break;
			case 'G':
				cout << "sin(" << a << ") = ";
				answer = sine(a);
				cout << "\nsin(" << b << ") = ";
				break;
			case 7:
				cout << "cos(" << a << ") = ";
				answer = cosine(a);
				cout << "\ncos(" << b << ") = ";
				break;
			case 0:
				flag = false;
				break;
			default:
				flag = true;
				break;
			}
			//user enters answer of equation
			cout << "\nEnter Answer: ";
			cin >> userAnswer;
			if (answer == userAnswer) {	//if answer is correct, get 1 point
				score++;
				cout << "\nCorrect!";
			}
			else {
				cout << "\nIncorrect!\nAnswer: " << answer;
			}
			cout << "\nScore: " << score;
			if (score >= 5)
				level++;
			if (score >= 10)
				level++;
			cout << endl;
			system("pause");
			questionNum++; //the question number
			question++;	//the number of question asked
		} while (question <= 5);
		round++;
		question = 1;
	} while (round <= 3);
}

/*
	game mode menu
	*/
void gameMode() {
	char choice;
	bool flag;
	do {
		flag = true;
		cout << "\nGame Mode:\n[A] Introductory\n[B] Intermediate\n[C] Advanced\n[0] Exit\n";
		cout << "Choice: ";
		cin >> choice;
		choice = toupper(choice);
		switch (choice) {
		case 'A':
			GameOperations(1);
			break;
		case 'B':
			GameOperations(2);
			break;
		case 'C':
			GameOperations(3);
			break;
		case '0':
			flag = false;
			break;
		default:
			cout << "\nInvalid Entry. Re-enter.\n";
			system("pause");
			flag = true;
		}
	} while (flag);
}

void menu() {
	int choice;
	bool flag;
	do {
		flag = true;;
		cout << "\nMenu:\n[1] Learn Mode\n[2] Game Mode\n[0] Exit";
		cout << "\nChoice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			learnModeOperations();
			break;
		case 2: 
			gameMode();
			break;
		case 0: 
			flag = false;
			cout << "\nMenu Exit.\n";
			break;
		default:
			cout << "\nInvalid Input. Re-enter.\n";
			system("pause");
			flag = true;
			break;
		}
	} while (flag);
}

int main() {
	menu();
	system("pause");
}