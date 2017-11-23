#include "BankAccount.h"

BankAccount::BankAccount() {
	balance = 0;
}
BankAccount::BankAccount(double b) {
	if (b < 0) {
		cout << "\nCannot Deposit Negative Dollars.";
		balance = 0.0;
	}
	else {
		balance = b;
	}

}
bool BankAccount::Credit(double b) {
	if (b < 0) {
		cout << "\nCannot Deposit Negative Dollars.";
		return false;
	}
	else {
		balance = balance + b;
		cout << "\nAdded to Account: $" << b;
		return true;
	}
}
bool BankAccount::Debit(double b) {
	if (b > balance) {
		cout << "\nDebit Amount Exceeded Account Balance.";
		return false;
	}
	else {
		balance = balance - b;
		cout << "\nWithdrew: $" << b;
		return true;
	}
}
double BankAccount::getBalance() {
	return balance;
}