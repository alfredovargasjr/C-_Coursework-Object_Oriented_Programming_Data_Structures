/*
	Alfredo Vargas
	CECS 282
	Lab 5
	Susan
	*/
using namespace std;
#include "Rectangle.h";

Rectangle::Rectangle() : length(1.0), width(1.0) {};	//inline 
//member initlaizer list
Rectangle::Rectangle(float x, float y) {	
	this->length = x;
	this->width = y;
}
float Rectangle::getLength() {
	return length;
}
float Rectangle::getWidth() {
	return width;
}
void Rectangle::setLength(float l) { 
	length = l; 
}
void Rectangle::setWidth(float w) { 
	width = w; 
}
//inline method
float Rectangle::getPerimeter() { 
	return ((2 * width) + (2 * length)); 
}
float Rectangle::getArea() {
	return (width * length); 
}



