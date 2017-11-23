#pragma once
#ifndef BankAccount_h
#define BankAccount_h
#include <iostream>
using namespace std;

class BankAccount {
	/*
		-protected data member
		-accesible for extended classes*/
protected:
	double balance;

	/*
		-public methods*/
public:
	//default constructor
	BankAccount();
	//overloaded constructor
	BankAccount(double b);
	//add money
	//return bool if able
	bool Credit(double b);
	//take out money
	//return bool if able
	bool Debit(double b);
	//return balance
	double getBalance();
};

#endif // !

