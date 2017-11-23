#pragma once
#ifndef Point_h
#define Point_h
using namespace std;
#include <string>
#include <iostream>

template <typename T, typename U>
class Point
{
private:
	T x;
	U y;

public:
	Point(T x, U y) {
		this->x = x;
		this->y = y;
	}
	Point() {
		// default
		x = 0;
		y = 0;
	}
	T getX() {
		return x;
	}
	U getY() {
		return y;
	}
	void setX(T x) {
		this->x = x;
	}
	void setY(U y) {
		this->y = y;
	}
	// toString()
	string toString() {
		strig sx = to_string(x);
		string sy = to_string(y);
		return "[ " + sx + ", " + sy + "]";
	}
};

#endif // !"Point_h"

