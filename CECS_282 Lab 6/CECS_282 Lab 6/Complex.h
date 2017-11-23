#ifndef Complex_h
#define Complex_h
#pragma once
#include <iostream>
using namespace std;

class Complex
{
	//private data members
private:
	double real;
	double imag;
	//public data members
public:
	//default constructor
	Complex();
	//overloaded constructor, double double
	Complex(double, double);
	//addition
	Complex operator+(const Complex&) const;
	//subtraction
	Complex operator-(const Complex&) const;
	//<< operator
	void operator<<(const Complex&) const;
	//>> operator
	Complex operator>>(const Complex&) const;
	//multiplication overload
	Complex operator*(const Complex&) const;
	//equal overloaded
	bool operator==(const Complex&) const;
	//noteqaul to overload
	bool operator!=(const Complex&) const;
	//division oveloaded
	Complex operator/(const Complex&) const;
	//return the imaginary data value
	double getImag();
	//return the real data value
	double getReal();
	//set the imaginary data value
	void setImag(double);
	//set the real data value
	void setReal(double);
	//return true if there is no imaginary value
	//otherwise return false, imaginary is not 0
	bool isReal();
	//return true if the there is an imaginary value
	//otherwise return false, imag is not 0
	bool isImag();
	//add two complex objects
	//implicit + explicit (object a)
	//return an object = to the addition
	Complex add(Complex);
	//subtract two complex objects
	//the values of this object will be the result of the subtracting the passed objects
	void sub(Complex, Complex);

	//multiply this object with object a
	//return new object with mult values
	Complex mul(Complex);
	void div(Complex, Complex);
	bool equal(Complex);
};

#endif