#include <iostream>
#include <vector>
#include <stdexcept>

#include "BankAccount.h"
#include "SavingAccount.h"
#include "Bank.h"

#include "BankAccount.cpp"
#include "SavingAccount.cpp"
#include "Bank.cpp"

using namespace std;

int main() {
    try {
        Bank testBank("TestBank");

        int accountNumber;
        string accountName;
        double balance, interestRate;

        // * Creating five SavingAccount objects

        cout << "Enter details for 5 saving accounts: \n";
        for (int i = 0; i < 5; i++) {
            
            cout << "Account " << i + 1 << ":\n";
            
            cout << "Enter account number: ";
            cin >> accountNumber;
            
            cout << "Enter account holder name: ";
            cin >> accountName;
            
            cout << "Enter balance: ";
            cin >> balance;
            
            cout << "Enter interest rate: ";
            cin >> interestRate;
            
            SavingAccount newSavingAccount(accountNumber, accountName, balance, interestRate);
            testBank.addSavingAccount(newSavingAccount);
        }

        cout << "\nInitial account information:\n";
        testBank.displayAccounts();

        // * Depositing £300 to two of the accounts and £500 to the others

        cout << "\nDepositing 300 euro to the first two accounts and 500 euro to the rest...\n";
        for (int i = 0; i < testBank.getSavingAccounts().size(); ++i) {
            if (i < 2) {
                testBank.getSavingAccounts()[i].deposit(300);
            }
            else {
                testBank.getSavingAccounts()[i].deposit(500);
            }
        }

        cout << "\nAccount information after deposit:\n";
        testBank.displayAccounts();

        // * Adding interest to all accounts

        cout << "\nAdding interest to all accounts...\n";
        for (int i = 0; i < testBank.getSavingAccounts().size(); ++i) {
            testBank.getSavingAccounts()[i].addInterest();
        }

        cout << "\nAccount information after adding interest:\n";
        testBank.displayAccounts();
    }
    catch (const invalid_argument& e) {
        cerr << "\nError: " << e.what() << "\nPlease enter the details again.\n";
    }

    return 0;
}
