#include "Complex.h"
#include <iostream>
#include <string>
using namespace std;

	//private data members
	//double real = 0.0;
	//double imag = 0.0;
	//public data members
	//default constructor
	Complex::Complex(){
		real = 0.0;
		imag = 0.0;
	}

	//overloaded constructor, double double
	Complex::Complex(double r, double i){
		real = r;
		imag = i;
	}

	//addition operator
	Complex Complex::operator+(const Complex& b) const {
		return Complex{ real + b.getReal, imag + b.getImag };
	}

	//subtraction operator
	Complex Complex::operator-(const Complex& b) const {
		return Complex{ real - b.getReal, imag - b.getImag };
	}
	
	//return the imaginary data value
	double Complex::getImag(){
		return imag;
	}

	//return the real data value
	double Complex::getReal() {
		return real;
	}

	//set the imaginary data value
	void Complex::setImag(double i) {
		imag = i;
	}

	//set the real data value
	void Complex::setReal(double r) {
		real = r;
	}

	//print the private data types
	void Complex::print() {
		cout << "(" << real << ", " << imag << ")" << endl;
	}

	//return true if there is no imaginary value
	//otherwise return false, imaginary is not 0
	bool Complex::isReal() {
		if (imag == 0)
			return true;
		return false;
	}

	//return true if the there is an imaginary value
	//otherwise return false, imag is not 0
	bool Complex::isImag() {
		if (imag != 0)
			return true;
		return false;
	}

	//add two complex objects
	//implicit + explicit (object a)
	//return an object = to the addition
	Complex Complex::add(Complex a) {
		double newReal = real + a.getReal();
		double newImag = imag + a.getImag();
		return { newReal, newImag };
	}

	//subtract two complex objects
	//the values of this object will be the result of the subtracting the passed objects
	void Complex::sub(Complex a, Complex b) {
		real = a.getReal() - b.getReal();
		imag = a.getImag() - b.getImag();
	}

	//multiply this object with object a
	//return new object with mult values
	Complex Complex::mul(Complex a) {
		double newReal = real * a.getReal();
		double newImag = imag * a.getImag();
		return { newReal, newImag };
	}

	void Complex::div(Complex a, Complex b) {
		real = a.getReal() / b.getReal();
		imag = a.getImag() / b.getImag();
	}

	bool Complex::equal(Complex a) {
		if (real == a.getReal())
			if (imag == a.getImag())
				return true;
		return false;
	}