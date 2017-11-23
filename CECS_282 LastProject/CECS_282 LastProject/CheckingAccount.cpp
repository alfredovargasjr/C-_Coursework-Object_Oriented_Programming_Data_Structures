#include "CheckingAccount.h"

CheckingAccount::CheckingAccount() {
	balance = 0;
	fee = 5;
}
CheckingAccount::CheckingAccount(double b, double f) {
	balance = b;
	fee = f;
}
void CheckingAccount::Credit(double b) {
	if (BankAccount::Credit(b)) {
		balance = balance - fee;
		cout << "\nFee: $" << fee;
	}
}
void CheckingAccount::Debit(double b) {
	if (BankAccount::Debit(b)) {
		balance = balance - fee;
		cout << "\nFee: $" << fee;
	}
}