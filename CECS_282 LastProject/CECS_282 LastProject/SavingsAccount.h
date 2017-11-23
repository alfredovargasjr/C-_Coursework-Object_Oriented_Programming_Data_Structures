#pragma once
#ifndef SavingsAccount_h
#define SavingsAccount_h
#include "BankAccount.h"

class SavingsAccount : public BankAccount {
private:
	double interestRate;
public:
	//default
	SavingsAccount();
	//overloaded 
	SavingsAccount(double b, double r);
	//overloaded, initial value
	SavingsAccount(double b);
	//reutrn calculated interest
	double calculateInterest();
	//overloaded withrdraw
	void Credit(double b);
};


#endif // !SavingsAccount_h

