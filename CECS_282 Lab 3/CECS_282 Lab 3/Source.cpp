
/*
	Alfredo Vargas
	CECS 282
	Lab 3
*/

#include <iostream>;
#include <ctype.h>;
#include <string>;

using namespace std;

/*
	determines what the char value is using header
*/
void characterValue(string s)
{
	char c = s[0];
	if (isdigit(c))
		cout << c << " is a digit.\n";
	if (isalpha(c))
		cout << c << " is alphabetic.\n";
	if (isspace(c))
		cout << c << " is a space.\n";
	if (ispunct(c))
		cout << c << " is a punctaution.\n";
	if (isalnum(c))
			cout << c << " is alphanumeric.\n";
	if (isupper(c))
		cout << c << " is uppercase.\n";
	if (islower(c))
		cout << c << " is lowercase.\n";
	if (isalpha(c)) {
		cout << c << " to uppercase -> " << char(toupper(c)) << endl;
		cout << c << " to lowercase -> " << char(tolower(c));
	}

}

/*
	prompt user for char input
	valid entry 
*/
int main()
{
	string str;
	int choice;
	bool flag, flagCont;
	do {
		flag = true;
		cout << "Enter a character: ";
		getline(cin, str);
		characterValue(str);
		do {
			flagCont = false;
			cout << "\nContinue Program?\n[1] Yes\n[2] No\n";
			cin >> choice;
			switch (choice) {
			case 1:
				break;
			case 2:
				flagCont = false;
				flag = false; //exit from loop/program;
				break;
			default:
				cout << "Invalid entry. Re-enter.";
				flagCont = true;	
			}
		} while (flagCont);
		cin.ignore();
	} while (flag);
	system("pause");
}

