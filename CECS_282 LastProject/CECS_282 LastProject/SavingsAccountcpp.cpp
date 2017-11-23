#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() {
	balance = 0;
}
SavingsAccount::SavingsAccount(double b, double r) {
	balance = b;
	interestRate = r;
}
SavingsAccount::SavingsAccount(double b) {
	balance = b;
}
double SavingsAccount::calculateInterest() {
	return getBalance() * interestRate;
}
void SavingsAccount::Credit(double b) {
	if (BankAccount::Credit(b)) {
		double interest = calculateInterest();
		balance = balance + interest;
		cout << "\nAdded Interest: $" << interest;
	}
}