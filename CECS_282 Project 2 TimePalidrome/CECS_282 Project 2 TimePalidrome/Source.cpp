
/*
	Alfredo Vargas
	CECS 282
	Project 2: Time/Date converter and Palidrome checker
	*/

using namespace std;
#include <iostream>;

/**
	return bool if h, m are acceptable values for time
	**/
bool validTime(int h, int m)
{
	if (h >= 0 && h < 24)
		if (m >= 0 && m < 60)
			return true;
	cout << "Invalid Time. Re-enter. \n\n";
	return false;
}
/*
	prompts user to input time with validation; hour, min.
	check to see if hour and min are afternoon or midnight; special values
	convert hour, min to the string representaion
*/
void getTime()
{
	int hour, min;
	do {
		cout << "\nEnter the time: ";
		cin >> hour >> min;
	} while (!validTime(hour, min));
	if (hour == 0 || hour == 24 && min == 0) {
	cout << "Midnight\n";
	}
	else 
	{
		if (hour == 12 && min == 0) {
			cout << "Afternoon\n";
		}
		else {
			if (hour > 12)
				hour = hour - 12;
			switch (hour)
			{
			case 0:
			case 12:
				cout << "Twelve ";
				break;
			case 1:
				cout << "One ";
				break;
			case 2:
				cout << "Two ";
				break;
			case 3:
				cout << "Three ";
				break;
			case 4:
				cout << "Four ";
				break;
			case 5:
				cout << "Five ";
				break;
			case 6:
				cout << "Six ";
				break;
			case 7:
				cout << "Seven ";
				break;
			case 8:
				cout << "Eight ";
				break;
			case 9:
				cout << "Nine ";
				break;
			case 10:
				cout << "Ten ";
				break;
			case 11:
				cout << "Eleven ";
				break;
			}
			switch (min / 10) {
			case 0:
				break;
			case 1:
				switch (min % 10)
				{
				case 0:
					cout << "Ten ";
					break;
				case 1:
					cout << "Eleven ";
					break;
				case 2:
					cout << "Twelve ";
					break;
				case 3:
					cout << "Thirteen ";
					break;
				case 4:
					cout << "Fourteen ";
					break;
				case 5:
					cout << "Fifteen ";
					break;
				case 6:
					cout << "Sixteen ";
					break;
				case 7:
					cout << "Seventeen ";
					break;
				case 8:
					cout << "Eighteen ";
					break;
				case 9:
					cout << "Nineteen ";
					break;
				}
				break;
			case 2:
				cout << "Twenty";
				break;
			case 3:
				cout << "Thirty";
				break;
			case 4:
				cout << "Fourty";
				break;
			case 5:
				cout << "Fifty";
				break;
			}
			if (!(min / 10 == 1)) 
			{
				switch (min % 10) {
				case 1:
					cout << "One ";
					break;
				case 2:
					cout << "Two ";
					break;
				case 3:
					cout << "Three ";
					break;
				case 4:
					cout << "Four ";
					break;
				case 5:
					cout << "Five ";
					break;
				case 6:
					cout << "Six ";
					break;
				case 7:
					cout << "Seven ";
					break;
				case 8:
					cout << "Eight ";
					break;
				case 9:
					cout << "Nine ";
					break;
				}
			}
			if (hour >= 12 && min > 0)
				cout << " PM";
			if(hour < 12)
				cout << " AM";
		}
	}

}

/*
	prompts the user for a 5 digit number with validation.
	return the 5 digit int
	*/
int getFiveDigitNum()
{
	bool flag;
	int num;
	do {
		flag = false;
		cout << "Enter a 5 Digit Number: ";
		cin >> num;
		if ((num / 10000 > 9) || (num / 10000 < 1)) {
			flag = true;
			cout << "Number is not 5 Digits. Re-enter.\n\n";
		}
	} while(flag);
	return num;
}

/*
	check if the number is a palidrome.
	gets each digit by reducing using mod and diving to find digit place
*/
void checkIfPalidrome()
{
	int num = getFiveDigitNum();
	//each letter stores each digit of the number
	int a = num / 10000;
	int b = (num % 10000) / 1000;
	int c = (num % 1000) / 100;
	int d = (num % 100) / 10;
	int e = (num % 10);
	if (a == e && b == d)
		cout << num << " is a palindrome :)\n";
	else
		cout << num << " is not a palindrome :(\n";
}

/*
	the main menu for the program.
	prompt user to choose an option of the menu with validation.
	*/
int menu()
{
	bool flag;
	do {
		flag = false;
		cout << "\nMenu: \n";
		cout << "[1] Time \n";
		cout << "[2] Palindrome\n";
		cout << "[0] Exit\n";
		cout << "Choice: ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: 
			getTime(); 
			break;
		case 2: 
			checkIfPalidrome(); 
			break;
		case 0: 
			cout << "Exit. \n";
			flag = true;
			break;
		default: 
			cout << "Invalid Entry. Re-enter. \n";
			break;
		}
	} while (!flag);
	return 0;
}

/*
	runs the menu
	*/
int main()
{
	menu();
	system("Pause");
}