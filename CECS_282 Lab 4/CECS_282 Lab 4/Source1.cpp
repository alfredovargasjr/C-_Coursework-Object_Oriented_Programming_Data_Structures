#include <iostream>;
using namespace std;
#include "DateTimeHeader.h";

void print(int a) {
	cout << a;
}

int get() {
	int var;
	cin >> var;
	print(var);
	return var;
}