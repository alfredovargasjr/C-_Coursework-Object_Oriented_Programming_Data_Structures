/*
	Alfredo Vargas
	CECS_282
	Project 7: Huge Integer, operation overloading
	Susan*/

#include <iostream>
#include "HugeInteger.h"

using namespace std;
/*
	- operations menu
	- prompt user to input an operation*/
void operations() {
	bool flag;  
	int choice;  
	HugeInteger a, b, c;  
	do {
		flag = false;   
		cout << "\nOperations: \n[1] Add\n[2] Subtract\n[3] Multiply \n[4] Divide \n[5] Are Equal \n[6] Are Not Equal \n[7] Is Greater than \n[8] Is Less that \n[9] Remainder \n[0] Exit";   
		cout << "\nChoice: ";   
		cin >> choice;   
		switch (choice) {
		case 1:    
			a = input();
			b = input();
			c = a + b;    
			cout << "\nResult: " << c;
			break;   
		case 2:    
			a = input();
			b = input();
			c = a - b;    
			cout << "\nResult: " << c;    
			break;   
		case 3: //multiply    
			a = input();
			b = input();
			c = a * b;    
			cout << "\nResult: " << c;    
			break;   
		case 4: //divide     
			a = input();
			b = input();
			c = a / b;    
			cout << "\nResult: " << c;    
			break;   
		case 5: //are equal    
			a = input();
			b = input();
			cout << "\n" << a << " == " << b << " = ";
			if (a == b)
				cout << "True";
			else
				cout << "False";
			break;
		case 6: //are not equal    
			a = input();
			b = input();
			cout << "\n" << a << " != " << b << " = ";
			if (a != b)
				cout << "True";
			else
				cout << "False";
			break;
			case 7: //is greater than  
				a = input();
				b = input();
				cout << "\n" << a << " > " << b << " = ";
				if (a > b)
					cout << "True";
				else
					cout << "False";
				break;
			case 8: //is less than  
				a = input();
				b = input();
				cout << "\n" << a << " < " << b << " = ";
				if (a < b)
					cout << "True";
				else
					cout << "False";
				break;
			case 9: //divide     
				a = input();
				b = input();
				c = a % b;
				cout << "\nResult: " << c;
				break;
			case 0:    
				flag = true;    
				break;   
			default:    
				cout << "\nInvalid Entry. Re-enter."; 
			flag = false;    
			cin.clear();    
			cin.ignore();    break;
		}
	} while (!flag);
}
/*
	- main menu of the program
	- prompt user to either go to operations menu, or exit program*/
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
		default:    cout << "\nInvalid Entry. Re-enter";    
			flag = false;    
			cin.clear();    
			cin.ignore();    
			break; 
		} 
	} while (!flag); }

int main() {
	HugeInteger n1{ 7654321 };    
	HugeInteger n2{ 7891234 };
	HugeInteger n3{ "99999999999999999999999999999" };
	HugeInteger n4{ "1" };
	HugeInteger n5{ "12341234" };
	HugeInteger n6{ "7888" };
	HugeInteger result;
	cout << "\nn1 is " << n1 << "\nn2 is " << n2 << "\nn3 is " << n3 << "\nn4 is " << n4 << "\nn5 is " << n5 << "\nn6 is " << n6 << "\nresult is " << result << "\n\n";
	//test the non member arithmetic function   
	//Include your test with an output  
	// test relational and equality operators    if (n1 == n2) {       cout << "n1 equals n2" << endl;    } 
	if (n1 != n2) { cout << "n1 is not equal to n2" << endl; }
	if (n1 < n2) { cout << "n1 is less than n2" << endl; }
	if (n1 <= n2) { cout << "n1 is less than or equal to n2" << endl; }
	if (n1 > n2) { cout << "n1 is greater than n2" << endl; }
	if (n1 >= n2) { cout << "n1 is greater than or equal to n2" << endl; }
	
	result = n1 + n2;    
	cout << n1 << " + " << n2 << " = " << result << "\n\n";    
	cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";    
	result = n1 + 9;    
	cout << n1 << " + " << 9 << " = " << result << endl;    
	result = n2 + 10000;
	cout << n2 << " + " << "10000" << " = " << result << endl;    
	result = n5 * n6;    
	cout << n5 << " * " << n6 << " = " << result << endl;    
	result = n5 - n6;    
	cout << n5 << " - " << n6 << " = " << result << endl;    
	
	result = n5 / n6;    
	cout << n5 << " / " << n6 << " = " << result << endl;
	
	result = n5 + n4 * n6;
	cout << n5 << " + " << n4 << " * " << n6 << " = " << result << endl;
	menu();  
	cout << "\n\nProgram Exit.\n";
	system("pause");
}