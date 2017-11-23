using namespace std;
#include "HugeInteger.h"
#include <iostream>

/*
	- default constructor, set init to 0*/
HugeInteger::HugeInteger() {
	number[0] = 0;
 }
/*
	- overloaded constructor with string, get string and input each character of the string to the hugeint array*/
HugeInteger::HugeInteger(string n) {
	for (int i = 0; i < n.size(); i++) {
		number[i] = n[n.size() - 1 - i] % 48;
		numDig++;
	}
}
/*
	- overloaded constructor with integer, get integer and parse it while inputing it into the hugeint*/
HugeInteger::HugeInteger(int n) {
	int num = n, i = 0;
	while (num > 0) {
		number[i] = num % 10;
		numDig++;
		i++;
		num = num / 10;
	}
}
//return the int array
int* HugeInteger::getNum() {
	return number;
}
//return the number of digits in the hugeint
int HugeInteger::getNumDig() {
	return numDig;
}
/*
	- return true if the hugeint is all zero*/
bool HugeInteger::isZero() {
	for (int i = 0; i < numDig; i++)
		if (number[i] != 0)
			return false;
	return true;
}
bool HugeInteger::isEqualTo(HugeInteger b) {
	for (int i = 0; i < 40; i++) {
		if (number[i] != b.getNum()[i])
			return false;
	}
	return true;
}
bool HugeInteger::isNotEqualTo(HugeInteger b) {
	for (int i = 0; i < 40; i++) {
		if (number[i] != b.getNum()[i])
			return true;
	}
	return false;
}
bool HugeInteger::isGreaterThan(HugeInteger b) {
	if (numDig > b.getNumDig())
		return true;
	if (numDig == b.getNumDig()) {
		for (int i = 0; i < numDig; i++) {
			if (number[numDig - 1 - i] > b.getNum()[numDig - 1 - i])
				return true;
		}
	}
	return false;
}
bool HugeInteger::isLessThan(HugeInteger b) {
	if (numDig < b.getNumDig())
		return true;
	if (numDig == b.getNumDig()) {
		for (int i = 0; i < numDig; i++) {
			if (number[numDig - 1 - i] < b.getNum()[numDig - 1 - i])
				return true;
		}
	}
	return false;
}
bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger b) {
	if (numDig > b.getNumDig())
		return true;
	if (numDig < b.getNumDig())
		return false;
	if (numDig == b.getNumDig()) {
		for (int i = 0; i < numDig; i++) {
			if (number[numDig - 1 - i] > b.getNum()[numDig - 1 - i])
				return true;
			if (number[numDig - 1 - i] == b.getNum()[numDig - 1 - i]);
			if (number[numDig - 1 - i] < b.getNum()[numDig - 1 - i])
				return false;
		}
	}
	return true;
}
bool HugeInteger::isLessThanOrEqualTo(HugeInteger b) {
	if (numDig < b.getNumDig())
		return true;
	if (numDig > b.getNumDig())
		return false;
	if (numDig == b.getNumDig()) {
		for (int i = 0; i < numDig; i++) {
			if (number[numDig - 1 - i] < b.getNum()[numDig - 1 - i])
				return true;
			if (number[numDig - 1 - i] == b.getNum()[numDig - 1 - i]);
			if (number[numDig - 1 - i] > b.getNum()[numDig - 1 - i])
				return false;
		}
	}
	return true;
}
/*
	overloaded operator ==, return true if hugeint is equal to b*/
bool HugeInteger::operator==(HugeInteger b) {
	for (int i = 0; i < 40; i++) {
		if (number[i] != b.getNum()[i])
			return false;
	}
	return true;
}
/*
	overloaded operator !=, return true if hugeint is not equal to b*/
bool HugeInteger::operator!=(HugeInteger b) {
	for (int i = 0; i < 40; i++) {
		if (number[i] != b.getNum()[i])
			return true;
	}
	return false;
}
/*
	overloaded operator >, return true if hugeint is bigger than b
	checks the number of digits in hugeint*/
bool HugeInteger::operator>(HugeInteger b) {
	if (numDig > b.getNumDig())
		return true;
	if (numDig == b.getNumDig()) {
		for (int i = 0; i < numDig; i++) {
			if (number[numDig - 1 - i] > b.getNum()[numDig - 1 - i])
				return true;
		}
	}
	return false;
}
/*
	- overloaded operator <, return true if hugeint is smaller than b
	- check number of digits in hugeint and compare*/
bool HugeInteger::operator<(HugeInteger b) {
	if (numDig < b.getNumDig())
		return true;
	if (numDig == b.getNumDig()) {
		for (int i = 0; i < numDig; i++) {
			if (number[numDig - 1 - i] < b.getNum()[numDig - 1 - i])
				return true;
		}
	}
	return false;
}
bool HugeInteger::operator>=(HugeInteger b) {
	if (numDig > b.getNumDig())
		return true;
	if (numDig < b.getNumDig())
		return false;
	if (numDig == b.getNumDig()) {
		for (int i = 0; i < numDig; i++) {
			if (number[numDig - 1 - i] > b.getNum()[numDig - 1 - i])
				return true;
			if (number[numDig - 1 - i] == b.getNum()[numDig - 1 - i]);
			if (number[numDig - 1 - i] < b.getNum()[numDig - 1 - i])
				return false;
		}
	}
	return true;
}
bool HugeInteger::operator<=(HugeInteger b) {
	if (numDig < b.getNumDig())
		return true;
	if (numDig > b.getNumDig())
		return false;
	if (numDig == b.getNumDig()) {
		for (int i = 0; i < numDig; i++) {
			if (number[numDig - 1 - i] < b.getNum()[numDig - 1 - i])
				return true;
			if (number[numDig - 1 - i] == b.getNum()[numDig - 1 - i]);
			if (number[numDig - 1 - i] > b.getNum()[numDig - 1 - i])
				return false;
		}
	}
	return true;
}
/*
	- overloaded iostream operator <<, return hugeint as string*/
ostream& operator<<(ostream& os, HugeInteger n)
{
	string s = "";
	for (int i = 0; i < n.getNumDig(); i++) {
		s = to_string(n.getNum()[i]) + s;
	}
	os << s;
	return os;
}
/*
	- prompt the user for input of huge int
	- return the input as a hugeint object*/
HugeInteger input() {
	cout << "Enter a number: ";
	string s;
	cin >> s;
	return { s };
}
/*
	- return hugeint b as a string*/
string output(HugeInteger b) {
	string s = "";
	for (int i = 0; i < b.getNumDig(); i++) {
		s = to_string(b.getNum()[i]) + s;
		/*
		sum = sum + (n.getNum()[i] * tenplace);
		tenplace = tenplace * 10;
		*/
	}
	return s;
}
/*
	- add */
HugeInteger add(HugeInteger a, HugeInteger b) {
	int temp[40] = { 0 };
	int carry = 0;
	int sum;
	string s = "";
	for (int i = 0; i < 40; i++) {
		sum = a.getNum()[i] + b.getNum()[i] + carry;
		if (sum > 9) {
			carry = 1;
			sum = sum % 10;
		}
		else
			carry = 0;
		temp[i] = sum;
		s = to_string(temp[i]) + s;
	}
	while(s.at(0) == '0')
		s.erase(0, 1);	
	return { s };
}

HugeInteger sub(HugeInteger a, HugeInteger b) {
	int temp[40] = { 0 };
	int carry = 0;
	bool isNeg = false;;
	int sub;
	HugeInteger t;
	if (a.getNumDig() < b.getNumDig()) {
		t = a;
		a = b;
		b = t;
		isNeg = true;
	}
	string s = "";
	for (int i = 0; i < 40; i++) {
		sub = (a.getNum()[i] - carry) - b.getNum()[i];
		if (sub < 0) {
			carry = 1;
			sub = sub + 10;
		}
		else
			carry = 0;
		temp[i] = sub;
		s = to_string(temp[i]) + s;
	}
	HugeInteger ifZero = { s };
	if (!ifZero.isZero()) {
		while (s.at(0) == '0')
			s.erase(0, 1);
	}
	else
		s = "0";
	if (isNeg)
		s.at(0) = s.at(0) * -1;
	return { s };
}
HugeInteger mult(HugeInteger a, HugeInteger b) {
	int temp[40] = { 0 };
	int carry = 0;
	int scarry = 0;
	int mult, shift = 0;
	if (a.getNumDig() == 0 || b.getNumDig() == 0)
		return { 0 };
	string s = "";
	for (int i = 0; i < b.getNumDig(); i++) {
		for (int j = 0; j <= a.getNumDig(); j++) {
			mult = (a.getNum()[j] * b.getNum()[i]) + carry;
			if (mult > 9) {
				carry = mult / 10;
				mult = mult % 10;
			}
			else
				carry = 0;
			temp[j + shift] = mult + temp[j + shift];
		}
		shift++;
	}
	for (int h = 0; h < 40; h++) {
		if (temp[h] > 9) {
			temp[h + 1] = (temp[h] / 10) + temp[h + 1];
			temp[h] = temp[h] % 10;
		}
		s = to_string(temp[h]) + s;
	}
	while (s.at(0) == '0')
		s.erase(0, 1);
	return { s };
}
/*
	- Overloaded operators */
HugeInteger HugeInteger::operator+(HugeInteger b) {
	string s = "";
	for (int i = 0; i < numDig; i++)
		s = to_string(number[i]) + s;
	return add({ s }, b);
}
HugeInteger HugeInteger::operator-(HugeInteger b) {
	string s = "";
	for(int i = 0; i < numDig; i++)
		s = to_string(number[i]) + s;
	return sub({ s }, b);
}
HugeInteger HugeInteger::operator*(HugeInteger b) {
	string s = "";
	for (int i = 0; i < numDig; i++)
		s = to_string(number[i]) + s;
	return mult({ s }, b);
}
HugeInteger HugeInteger::operator/(HugeInteger b) {
	HugeInteger sum = b;
	int t = 0;
	while (sum <= *this) {
		sum = sum + b;
		t++;
	}
	return {t};
}

HugeInteger HugeInteger::operator%(HugeInteger b) {
	HugeInteger sum = b;
	int t = 0;
	while ((sum + b) <= *this) {
		sum = sum + b;
	}
	return *this - sum;
}
