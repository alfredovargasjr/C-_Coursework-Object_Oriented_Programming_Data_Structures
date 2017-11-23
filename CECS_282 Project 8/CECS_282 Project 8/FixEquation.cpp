
#include <iostream>
#include "PostFix.h"
#include "GenericStack.h"

using namespace std;

void menu() {
	char choice;
	string s;
	bool flag = false;
	do {
		cout << "\nMenu: \n[1] InFix to PostFix \n[2] PostFix to InFix \n[0] Exit \nChoice: ";
		cin >> choice;
		switch (choice) {
		case '1':
			cout << "\nEnter InFix: ";
			cin >> s;
			cout << "\nPostFix: " << toPostFix(s);
			cin.clear();
			break;
		case '2':
			cout << "\nEnter PostFix: ";
			cin >> s;
			cout << "\nPostFix: " << toInFix(s);
			break;
		case '0':
			flag = true;
			break;
		default:
			cout << "\nInvalid entry. Reenter. ";
			cin.clear();
			flag = false;
		} 
	}while (!flag);

}

int main() {
	menu();
	system("pause");
	return 0;
}




