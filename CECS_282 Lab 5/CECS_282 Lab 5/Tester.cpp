/*
Alfredo Vargas
CECS 282
Lab 5
Susan
*/

using namespace std;
#include <iostream>;
#include "Rectangle.h";

float withinRange() {
	float num;
	bool flag;
	do {
		flag = false;
		cin >> num;
		if (num < 20.0 && num > 0.0) {
			return num;
		}
		else {
			cout << "\nNumber is out of range. Re-enter.";
			flag = true;
			cin.clear();
		}
	} while (flag);
}

int main() {
	Rectangle r1(1, 4); //implicit constructor
	Rectangle r2 = Rectangle(5, 2);	//explicit constructor
	Rectangle *rp = new Rectangle(3.0 , 1);
	(rp)->setWidth(2.1);
	Rectangle * ptrRecArray = new Rectangle[5];
	for (int i = 0; i < 2; i++) {
		cout << "Enter Rectangle Dimensions: ";
		ptrRecArray[i] = Rectangle(withinRange(), withinRange());
		cout << "(" << ptrRecArray[i].getLength() << "," << ptrRecArray[i].getWidth() << ")" << endl;
	}
	cout << "Area: " << r2.getArea() << "\nPerimeter: " << r2.getPerimeter();
	delete[] ptrRecArray;
	cout << "\nArray destroyed.";
	delete rp;
	cout << "\nrp destroyed.";
	system("pause");
}


