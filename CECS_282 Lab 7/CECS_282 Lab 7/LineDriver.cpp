/*
	Alfredo Vargas
	CECS 282 
	Lab 7: Generic, template classes and objects
	Susan
	*/
using namespace std;
#include "Line.h"
#include "Point.h"

int main() {
	Point<int, int> p1 = Point<int, int>(9, 3);
	Point<int, int> p3 = Point<int, int>(6, 2);
	Point<double, double> p2 = Point<double, double>(5.0, 8.2);
	Point<int, double> p4 = { 11, 5.6 };
	cout << "P1: " + p1.toString();
	cout << "\nP2: " + p2.toString() << endl;
	Line<Point<int, int>, Point<int, int>, int> l1 = { p1, p3 };
	Line<Point<int, int>, Point<double, double>, int> ln2 = { p3, p2 };
	Line<Point<double, double>, Point<int, double>, int> ln3 = { p2, p4 };
	cout << l1.toString() << endl;
	cout << ln2.toString() << endl;
	cout << ln3.toString() << endl;
	system("pause");
	return 0;
}