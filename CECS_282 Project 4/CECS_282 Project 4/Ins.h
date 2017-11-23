#pragma once

using namespace std;
#include <iostream>;

void getVal(double * a) {
	bool flag;
	do {
		flag = true;
		cout << "Enter Value: ";
		cin >> *a;
		flag = false;
	} while (flag);
}