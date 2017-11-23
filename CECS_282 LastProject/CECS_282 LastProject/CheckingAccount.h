#pragma once
#ifndef CheckingAccount_h
#define CheckingAccount_h
#include "BankAccount.h"

class CheckingAccount : public BankAccount{
private:
	double fee;

public:
	//default
	CheckingAccount();
	//overloaded
	CheckingAccount(double b, double f);
	//add money
	void Credit(double b);
	//withdraw money
	void Debit(double b);
};
#endif // !CheckingAccount_h

