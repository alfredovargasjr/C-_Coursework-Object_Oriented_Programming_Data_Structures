#pragma once
#include <math.h>;
#include <string>;

double genRand() {
	return 0;
}

double addition(double a, double b) {
	return a + b;
}

double subtraction(double a, double b) {
	return a - b;
}

double multiplication(double a, double b) {
	return a * b;
}

/*
divide the first argument by the second one*/
double dDivision(double a, double b) {
	return a / b;
}

/*
divide the integers */
int intDiv(double a, double b) {
	return int(a) / int(b);
}

/*
find the remainder of the two nums*/
int modul(double a, double b) {
	return int(a) % int(b);
}

double pow(double a, double b) {
	if (b == 0)
		return 1;
	if (b == 1)
		return a;
	if (b >= 0)
		return a * pow(a, b - 1);
}

//find sine of an angle
//sin(radians)
//radians = a * pi / 180
double sine(double a) {
	return sin(a * 3.141592 / 180 );
}

//cos(radians)
double cosine(double a) {
	return cos(a * 3.141592 / 180);
}

void outs(string s, double a, double b) {
	cout << a << " " << s << " " << b << " = ";
}
