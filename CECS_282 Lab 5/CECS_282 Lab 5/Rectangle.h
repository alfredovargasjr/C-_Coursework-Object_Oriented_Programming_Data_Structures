#pragma once
#ifndef RECTANGLE_H
#define Rectangle_h

using namespace std;

class Rectangle{
private:
	float length;
	float width;
public:
	Rectangle();
	Rectangle(float, float);
	float getWidth();
	float getLength();
	void setWidth(float);
	void setLength(float);
	float getPerimeter();
	float getArea();
};


#endif // !
