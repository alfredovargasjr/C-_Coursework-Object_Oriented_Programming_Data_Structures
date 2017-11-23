/*
Alfredo Vargas
CECS 282
Lab 6: Complex numbers
Susan
*/

#include <iostream>
#include "Complex.h"
using namespace std;

/*
Operations for the complex numbers
prompt user with menu
return results
*/
void operations() {
	bool flag;
	int choice;
	Complex a, b, c;
	do {
		flag = false;
		cout << "\nOperations: \n[1] Add\n[2] Subtract\n[3] Multiply \n[4] Divide \n[5] Are Equal \n[6] Is Real \n[7] Is Complex \n[0] Exit";
		cout << "\nChoice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			a = getComplex();
			b = getComplex();
			c = a + b;
			cout << "\nResult: ";
			c.print();
			break;
		case 2:
			a = getComplex();
			b = getComplex();
			c = a - b;
			cout << "\nResult: ";
			c.print();
			break;
		case 3:	//multiply
			a = getComplex();
			b = getComplex();
			c = a * b;
			cout << "\nResult: ";
			c.print();
			break;
		case 4:	//divide 
			a = getComplex();
			b = getComplex();
			a.div(a, b);
			cout << "\nResult: ";
			a.print();
			break;
		case 5:	//are equal
			a = getComplex();
			b = getComplex();
			cout << "\nEqual: ";
			if (a == b)
				cout << "True";
			else
				cout << "False";
			break;
		case 6:	//is real
			a = getComplex();
			cout << "\nIs Real: ";
			if (a.isReal() == 1)
				cout << "True";
			else
				cout << "False";
			break;
		case 7: //is complex
			a = getComplex();
			cout << "\nIs Imaginary: ";
			if (a.isImag() == 1)
				cout << "True";
			else
				cout << "False";
			break;
		case 0:
			flag = true;
			break;
		default:
			cout << "\nInvalid Entry. Re-enter.";
			flag = false;
			cin.clear();
			cin.ignore();
			break;
		}
	} while (!flag);
}

/*
return two double values
test for double values
*/
Complex getComplex() {
	double a, b;
	bool flag;
	do {
		try {
			flag = false;
			cout << "\n\tEnter Real: ";
			cin >> a;
			cout << "\n\tEnter Imaginary: ";
			cin >> b;
		}
		catch (string s) {
			cout << "\nInvlid Entry. Re-enter.";
			flag = true;
			cin.clear();
			cin.ignore();
		}
		catch (char c) {
			cout << "\nInvlid Entry. Re-enter.";
			flag = true;
			cin.clear();
			cin.ignore();
		}
	} while (flag);
	return { a, b };

}

/*
main menu
prompt user choice of options
input validation
*/
void menu() {
	bool flag;
	int choice;
	do {
		flag = false;
		cout << "\nMenu:\n[1] Operations\n[0] Exit\nChoice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			operations();
			break;
		case 0:
			flag = true;
			break;
		default:
			cout << "\nInvalid Entry. Re-enter";
			flag = false;
			cin.clear();
			cin.ignore();
			break;
		}
	} while (!flag);
}


int main() {
	menu();
	cout << "\n\nProgram Exit.";
	system("pause");
}
