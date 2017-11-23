/*
	Alfredo Vargas
	CECS 282
	Lab 4: Lab struct
	Susan
	*/
using namespace std;
#include <iostream>;

#include "DT1.h";
#include "DT2.h";
#include "DateTimeHeader.h";

struct DateTime3 {
	char day;
	int time;
	short year;
	char month;
};

union uDateTime1{
	int time;
	char day;
	char month;
	short year;
};

union uDateTime2 {
	char day;
	int time;
	char month;
	short year;
};

union uDateTime3 {
	char day;
	int time;
	short year;
	char month;
};

int main() {
	//using structs
	DateTime1 dt1 = { 3, 'T', 'M', 2017 };
	DateTime2 dt2 = { 'T', 3, 'M', 2017 };
	DateTime3 dt3 = { 'T', 3, 2017, 'M' };
	cout << "dt1: " << dt1.day << " " << dt1.month << " " << dt1.time << " " << dt1.year << "\nSize: " << sizeof(dt1) << endl;
	cout << "\ndt2: " << dt2.day << " " << dt2.month << " " << dt2.time << " " << dt2.year << "\nSize: " << sizeof(dt2) << endl;
	cout << "\ndt3: " << dt3.day << " " << dt3.month << " " << dt3.time << " " << dt3.year << "\nSize: " << sizeof(dt3) << endl;
	//using union
	
	uDateTime1 udt1 = { 3 };
	uDateTime2 udt2 = { 'T'};
	uDateTime3 udt3 = { 'T'};
	cout << "udt1: " << udt1.day << " " << udt1.month << " " << udt1.time << " " << udt1.year << "\nSize: " << sizeof(udt1) << endl;
	cout << "\ndt2: " << udt2.day << " " << udt2.month << " " << udt2.time << " " << udt2.year << "\nSize: " << sizeof(udt2) << endl;
	cout << "\ndt3: " << udt3.day << " " << udt3.month << " " << udt3.time << " " << udt3.year << "\nSize: " << sizeof(udt3) << endl;
	
	system("pause");
}