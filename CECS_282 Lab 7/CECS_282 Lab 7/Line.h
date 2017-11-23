#pragma once
#ifndef Line_h
#define Line_h
using namespace std;
#include <string>
#include "Point.h"
#include <math.h>

template <class U, class V, typename T>
class Line {
	// Private member variables
private:
	U begin;
	V end;
	// Declare begin and end as instances of Point
public:
	// Define Constructors
	Line(T x1, T y1, T x2, T y2) {
		begin = U(x1, y1);
		end = V(x2, y2);
	}
	Line(U begin, V end) {
		this->begin = begin;
		this->end = end;
	}
	// Public getter and setter for private variables
	U getBegin() {
		return begin;
	}
	V getEnd() {
		return end;
	}

	void setBegin(U p) {
		begin = p;
	}
	void setEnd(V p) {
		end = p;
	}
	//toString method
	string toString() {
		return "Line: [" + begin.toString() + ", " + end.toString() + "] " + "Length: " + to_string(getLength());
	}
	//DReturns the length of the line
	double getLength() {
		double length = sqrt(pow((end.getX() - begin.getX()), 2) + pow((end.getY() - begin.getY()), 2));
		return length;
	}
};


#endif
