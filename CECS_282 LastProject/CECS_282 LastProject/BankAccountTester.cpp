
#include "CheckingAccount.h"
#include "SavingsAccount.h"
using namespace std;

/*
	-main menu for the bank accounts
	-sub menu as well for deposit and withdraw
	*/
void menu() {
	char choice, choice2;
	double initial, interest, fee;
	double money;
	BankAccount bank;
	CheckingAccount check;
	SavingsAccount save;
	bool flag, actionFlag;
	do {
		actionFlag = false;
		flag = false;
		cout << "Menu: \nCreate An Account - \n[1] Banking Account \n[2] Savings Account \n[3] Checking Account \n[0] Exit \nChoice: ";
		cin >> choice;
		switch (choice) {
		case '1':
			cout << "\nEnter Your Initial Deposit: ";
			cin >> initial;
			bank = BankAccount(initial);
			while (!actionFlag) {
				cout << "\nAccount Menu: \n[1] Deposit Money \n[2] Withdraw Money \n[0] Account Menu \nChoice: ";
				cin >> choice2;
				switch (choice2) {
				case '1': cout << "\nDeposit: "; cin >> money; bank.Credit(money); cout << "\nBalance: $" << bank.getBalance(); break;
				case '2': cout << "\nDeposit: "; cin >> money; bank.Debit(money); cout << "\nBalance: $" << bank.getBalance(); break;
				case '0': actionFlag = true; break;
				default: cout << "\nInvalid Entry. Re-enter"; cin.clear();
				}
			}
			break;
		case '2':
			cout << "\nEnter Your Initial Deposit: ";
			cin >> initial;
			cout << "\nEnter Interest Rate: ";
			cin >> interest;
			save = SavingsAccount(initial, interest);
			while (!actionFlag) {
				cout << "\nAccount Menu: \n[1] Deposit Money \n[2] Withdraw Money \n[0] Account Menu \nChoice: ";
				cin >> choice2;
				switch (choice2) {
				case '1': cout << "\nDeposit: "; cin >> money; save.Credit(money); cout << "\nBalance: $" << save.getBalance(); break;
				case '2': cout << "\nDeposit: "; cin >> money; save.Debit(money); cout << "\nBalance: $" << save.getBalance(); break;
				case '0': actionFlag = true; break;
				default: cout << "\nInvalid Entry. Re-enter"; cin.clear();
				}
			}
			break;
		case '3':
			cout << "\nEnter Your Initial Deposit: ";
			cin >> initial;
			cout << "\nEnter Fee: ";
			cin >> fee;
			check = CheckingAccount(initial, fee);
			while (!actionFlag) {
				cout << "\nAccount Menu: \n[1] Deposit Money \n[2] Withdraw Money \n[0] Account Menu \nChoice: ";
				cin >> choice2;
				switch (choice2) {
				case '1': cout << "\nDeposit: "; cin >> money; check.Credit(money); cout << "\nBalance: $" << check.getBalance(); break;
				case '2': cout << "\nDeposit: "; cin >> money; check.Debit(money); cout << "\nBalance: $" << check.getBalance(); break;
				case '0': actionFlag = true; break;
				default: cout << "\nInvalid Entry. Re-enter"; cin.clear();
				}
			}
			break;
		case '0':
			flag = true;
			break;
		default:
			cout << "\nInvalid Entry. Re-enter";
			cin.clear();
			break;
		}
		} while (!flag);
}

/*
	-main
	-pause the system*/
int main(){
	menu();
	system("pause");
	return 0;
}