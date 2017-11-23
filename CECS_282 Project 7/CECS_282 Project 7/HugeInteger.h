#pragma once
#ifndef HugeInteger_h
#define HugeInteger_h
using namespace std;
#include <String>

class HugeInteger {
private:
	int number[40] = { 0 };
	int numDig = 0;

public:
	HugeInteger();
	HugeInteger(string);
	HugeInteger(int);
	int* getNum();
	int getNumDig();
	bool isZero();
	bool isEqualTo(HugeInteger);
	bool isNotEqualTo(HugeInteger);
	bool isGreaterThan(HugeInteger);
	bool isLessThan(HugeInteger);
	bool isGreaterThanOrEqualTo(HugeInteger);
	bool isLessThanOrEqualTo(HugeInteger);

	bool operator==(HugeInteger b);
	bool operator!=(HugeInteger b);
	bool operator>(HugeInteger b);
	bool operator<(HugeInteger b);
	bool operator>=(HugeInteger b);
	bool operator<=(HugeInteger b);


	HugeInteger operator+(HugeInteger b);
	HugeInteger operator-(HugeInteger);
	HugeInteger operator*(HugeInteger);
	HugeInteger operator/(HugeInteger);
	HugeInteger operator%(HugeInteger);

	friend ostream& operator<<(ostream& os, HugeInteger n);
	friend HugeInteger input();
	friend string output(HugeInteger);
	friend HugeInteger add(HugeInteger, HugeInteger);
	friend HugeInteger sub(HugeInteger, HugeInteger);
	friend HugeInteger mult(HugeInteger, HugeInteger);
	friend HugeInteger div(HugeInteger, HugeInteger);
	friend HugeInteger remndr(HugeInteger, HugeInteger);
};

#endif 
