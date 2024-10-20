#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

#include "BankAccount.h"
#include "SavingAccount.h"
#include "Bank.h"

#include "BankAccount.cpp"
#include "SavingAccount.cpp"
#include "Bank.cpp"

using namespace std;

void printMenu();
void addBankAccount(Bank& bank);
void addSavingAccount(Bank& bank);
void removeBankAccount(Bank& bank);
void removeSavingAccount(Bank& bank);
void depositToBankAccount(Bank& bank);
void withdrawFromBankAccount(Bank& bank);
void depositToSavingAccount(Bank& bank);
void withdrawFromSavingAccount(Bank& bank);
void addInterestToSavingAccount(Bank& bank);
void displayAllAccounts(Bank& bank);


int main() {
    try {
        string bankName;
        cout << "Enter the name of the bank: ";
        cin >> bankName;

        Bank bank(bankName);

        int choice;

        while(true) {
            printMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;
            cout << endl;

            switch(choice){
                case 1:
                    addBankAccount(bank);
                    break;
                case 2:
                    addSavingAccount(bank);
                    break;
                case 3:
                    removeBankAccount(bank);
                    break;
                case 4:
                    removeSavingAccount(bank);
                    break;
                case 5:
                    depositToBankAccount(bank);
                    break;
                case 6:
                    withdrawFromBankAccount(bank);
                    break;
                case 7:
                    depositToSavingAccount(bank);
                    break;
                case 8:
                    withdrawFromSavingAccount(bank);
                    break;
                case 9:
                    addInterestToSavingAccount(bank);
                    break;
                case 10:
                    displayAllAccounts(bank);
                    break;
                case 11:
                    cout << "Exiting...\n";
                    return 0;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    }
    catch (const invalid_argument& e) {
        cerr << "\nError: " << e.what() << "\nPlease enter the details again.\n";
    }

    return 0;
}

void printMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add a bank account\n";
    cout << "2. Add a saving account\n";
    cout << "3. Remove a bank account\n";
    cout << "4. Remove a saving account\n";
    cout << "5. Deposit to an bank account\n";
    cout << "6. Withdraw from a bank account\n";
    cout << "7. Deposit to a saving account\n";
    cout << "8. Withdraw from a saving account\n";
    cout << "9. Add interest to a saving account\n";
    cout << "10. Display all accounts\n";
    cout << "11. Exit\n";
}

void addBankAccount(Bank& bank) {
    int accountNumber;
    string accountName;
    double balance;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter account holder name: ";
    cin >> accountName;

    cout << "Enter balance: ";
    cin >> balance;

    BankAccount newBankAccount(accountNumber, accountName, balance);
    bank.addBankAccount(newBankAccount);
}

void addSavingAccount(Bank& bank) {
    int accountNumber;
    string accountName;
    double balance, interestRate;

    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter account holder name: ";
    cin >> accountName;

    cout << "Enter balance: ";
    cin >> balance;

    cout << "Enter interest rate: ";
    cin >> interestRate;

    SavingAccount newSavingAccount(accountNumber, accountName, balance, interestRate);
    bank.addSavingAccount(newSavingAccount);
}

void removeBankAccount(Bank& bank) {
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;

    bank.removeBankAccount(accountNumber);
}

void removeSavingAccount(Bank& bank) {
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;

    bank.removeSavingAccount(accountNumber);
}

void depositToBankAccount(Bank& bank) {
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter amount to deposit: ";
    cin >> amount;

    for (int i = 0; i < bank.getBankAccounts().size(); ++i) {
        if (bank.getBankAccounts()[i].getAccountNumber() == accountNumber) {
            bank.getBankAccounts()[i].deposit(amount);
            return;
        }
    }
    throw invalid_argument("Account number not found");
}

void withdrawFromBankAccount(Bank& bank) {
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    for (int i = 0; i < bank.getBankAccounts().size(); ++i) {
        if (bank.getBankAccounts()[i].getAccountNumber() == accountNumber) {
            bank.getBankAccounts()[i].withdraw(amount);
            return;
        }
    }
    throw invalid_argument("Account number not found");
}

void depositToSavingAccount(Bank& bank) {
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter amount to deposit: ";
    cin >> amount;

    for (int i = 0; i < bank.getSavingAccounts().size(); ++i) {
        if (bank.getSavingAccounts()[i].getAccountNumber() == accountNumber) {
            bank.getSavingAccounts()[i].deposit(amount);
            return;
        }
    }
    throw invalid_argument("Account number not found");
}

void withdrawFromSavingAccount(Bank& bank) {
    int accountNumber;
    double amount;
    cout << "Enter account number: ";
    cin >> accountNumber;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    for (int i = 0; i < bank.getSavingAccounts().size(); ++i) {
        if (bank.getSavingAccounts()[i].getAccountNumber() == accountNumber) {
            bank.getSavingAccounts()[i].withdraw(amount);
            return;
        }
    }
    throw invalid_argument("Account number not found");
}

void addInterestToSavingAccount(Bank& bank) {
    int accountNumber;
    cout << "Enter account number: ";
    cin >> accountNumber;

    for (int i = 0; i < bank.getSavingAccounts().size(); ++i) {
        if (bank.getSavingAccounts()[i].getAccountNumber() == accountNumber) {
            bank.getSavingAccounts()[i].addInterest();
            return;
        }
    }
    throw invalid_argument("Account number not found");
}

void displayAllAccounts(Bank& bank) {
    bank.displayAccounts();
}
